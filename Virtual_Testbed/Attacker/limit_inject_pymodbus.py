from pymodbus.client import ModbusTcpClient

client = ModbusTcpClient('192.168.88.10')
client.connect()
client.write_register(1,200)
client.close()