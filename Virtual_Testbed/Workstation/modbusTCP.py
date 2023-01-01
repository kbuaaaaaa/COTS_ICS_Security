from pymodbus.client import ModbusTcpClient
client = ModbusTcpClient('127.0.0.1')
client.connect()