import socket
import sys

# Create a UDP socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# Bind the socket to the port
s.bind(("127.0.0.1", 9090))

while True:
    print("####### Server is listening #######")
    data, address = s.recvfrom(4096)
    print("\n\n Server received: ", data, "\n\n")