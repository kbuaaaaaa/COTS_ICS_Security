We could imagine the attacker has attached themselve to the router.
All my components are also connected to the pfsense router via ethernet.
I first use ifconfig to see my ip and the network I am on (192.168.88.201).
I use nmap to perform network scan and discover 192.168.88.1 , 192.168.88.10 , 192.168.88.202
I cannot sniff on ALL traffic, I can only see ones that goes through my attacker.
I decided to use Ettercap to scan for host and perform ARP poisoning on PLC (192.168.88.10) and Workstation (192.168.88.202).
Then I was able to capture all the traffic and see their content.

From observation:
ScadaBR make 4 types of request every to the PLC ~300ms
1. Read Coils
4. Read Input Register
3. Read Holding Register
2. Read Discrete Input

Since we know this is a water tank, the varying variable will be the level of water. We observe that to be the input register of the PLC.
When starting and stopping PLC, workstation sent 5. Write Single Coil function packet.

