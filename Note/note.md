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
- DoS on Docker container

Attack on Communication :
- MitM between PLC-PLC and PLC-Workstation :
    - ARP poisoning
    - Invalid response
    - False error response
    - False measurement response
    - Communication force restart

Attack on PLC :
- DoS on PLC : Bad CRC, Fake read bomb

Plan for next week onward :
1. Study online resources for Simulink\Factory IO, OpenPLC. : Done
2. Implement the water tank simulator. : Done
3. Implement PLC program. : Done
4. Configure the simulation-plc communication. : Done with improvements to be made
5. Configure the plc-workstation communication (using PyModbus)

