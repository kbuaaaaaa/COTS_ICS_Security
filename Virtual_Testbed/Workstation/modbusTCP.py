from pymodbus.client import ModbusTcpClient
client = ModbusTcpClient('localhost')
client.connect()