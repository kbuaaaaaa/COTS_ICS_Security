PLC-Simulink-Docker
- Guide for OpenPLC-Simulink : https://github.com/thiagoralves/OpenPLC_Simulink-Interface
- Example Docker OpenPLC image : https://hub.docker.com/r/ioexpert/netpi-openplc
- Matlab to Docker : https://uk.mathworks.com/help/compiler/package-matlab-standalone-applications-into-docker-images.html
- Workstation to OpenPLC : https://www.youtube.com/watch?v=c4esqcNun7k
- Someone else's : https://github.com/Fortiphyd/GRFICSv2/blob/master/README.md
- Ladder logic program : https://www.sanfoundry.com/plc-program-control-level-single-tank/
- Santiago's github link : https://github.com/sfl0r3nz05/ICSVirtual , https://github.com/sfl0r3nz05/DepSimModStandAppDocker
- Windows VM on Docker container : https://medium.com/axon-technologies/installing-a-windows-virtual-machine-in-a-linux-docker-container-c78e4c3f9ba1



Some attack links :
- https://connormcgarr.github.io/eko2019-exe/


Reconnaissance
- Nmap network scan
- Wireshark packet analyse
- Try to identify devices on the network, their address, and the operations perform.

Attack on workstation :
- Reverse TCP using Metasploit
- Attempt at ROP : Bypassing ASLR 

Attack on Communication : Make sure to understand Modbus architecture and security mechanism.
- MitM between PLC-Workstation :
    - ARP poisoning : Display false status on workstation, Block the workstation from giving PLC the commands
        - Create a phantom PLC
            - Make decisions on what phantom PLC should do
        - ScadaBR will try to connect to the PLC on port 502 (the modbus port)
        - Race the correct PLC to connect with ScadaBR.
    - Invalid response
        - Forge a Modbus message for a variable in PLC or in Workstation with wrong data type or smth.
        - Can try both ways since both PLC and Workstation is open to Modbus connection, doesnt seem to have authentication
    - False measurement response
        - Forge a Modbus message from PLC to Workstation with False Height Level
    - Communication force restart
        - Not sure how to do this yet

Attack on PLC :
    - DoS on PLC : Bad CRC, Fake read bomb
        - Accidentally did this already while trying to synchronise the communication
        - But how is this related to OS vulnerability
    - DoS on Docker container
        - Needs more research
        - This could be a bonus to os

