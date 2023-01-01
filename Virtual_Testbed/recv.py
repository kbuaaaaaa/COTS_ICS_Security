import socket
import sys


# Create a UDP socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# Bind the socket to the port
port = int(sys.argv[1])
s.bind(("127.0.0.1", port))

while True:
    print("####### Server is listening #######")
    data, address = s.recvfrom(4096)
    print("\n\n Server received: ", data, "\n\n")