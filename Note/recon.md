Since all my components are connected to the pfsense router via ethernet.
I cannot sniff on ALL traffic, I can only see ones that goes through my attacker.
I decided to use Ettercap to scan for host and perform ARP poisoning on PLC (192.168.88.10) and Workstation (192.168.88.202).
Then I was able to capture all the traffic and identify them as Modbus/TCP packets.