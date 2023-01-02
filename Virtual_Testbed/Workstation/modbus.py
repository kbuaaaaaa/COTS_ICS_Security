from pymodbus.client import ModbusTcpClient

client = ModbusTcpClient('127.0.0.1')
client.connect()
client.write_coil(2, True)
client.write_coil(3, False)
client.write_register(1,100)
client.write_register(2,80)
while True:
    result = client.read_input_registers(0,1)
    print(result.registers)
