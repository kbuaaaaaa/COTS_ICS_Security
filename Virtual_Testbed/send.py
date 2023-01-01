import socket
import sys


# Create a UDP socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# Bind the socket to the port
port = int(sys.argv[1])
s.connect(("127.0.0.1", port))

while True:
    data = 0
    s.send(data.to_bytes(2, 'big'))