from pymodbus.client import ModbusTcpClient

client = ModbusTcpClient('192.168.88.10')
client.connect()
while True :  
    client.read_input_registers(0,100)
    client.read_coils(0,100)
    client.read_discrete_inputs(0,100)
    client.read_holding_registers(0,100)