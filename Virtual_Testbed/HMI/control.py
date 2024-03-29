from tkinter import *
from pymodbus.client import ModbusTcpClient

client = ModbusTcpClient('192.168.88.10')
client.connect()

control = Tk()
control.title("Control Panel")
control.geometry("550x400")
control.config(background="white")

def StartPLC():
    client.write_coil(2,True)
    client.write_coil(3,False)

def StopPLC():
    client.write_coil(2,False)
    client.write_coil(3,True)

def SetLowLimit():
    client.write_register(2,int(low.get()))

def SetHighLimit():
    client.write_register(1,int(high.get()))

appName = Label(control,text="Control Panel",font=("arial",25,"bold"))
appName.place(x=125, y=10,height=40,width=300)

start = Button(control,text="Start",fg="green",font=("arial",20),command=StartPLC)
start.place(x=125, y=60,height=40,width=150)

stop = Button(control,text="Stop",fg="red",font=("arial",20),command=StopPLC)
stop.place(x=275, y=60,height=40,width=150)

lowLimit = Label(control,text="Low Limit:",font=("arial",10,"bold"))
lowLimit.place(x=50, y=110,height=40,width=150)

low = Entry(control,font=("arial",20))
low.place(x=200, y=110,height=40,width=150)

lowset = Button(control,text="Set Value",font=("arial",20),command=SetLowLimit)
lowset.place(x=350, y=110,height=40,width=150)

highLimit = Label(control,text="High Limit:",font=("arial",10,"bold"))
highLimit.place(x=50, y=160,height=40,width=150)

high = Entry(control,font=("arial",20))
high.place(x=200, y=160,height=40,width=150)

highset = Button(control,text="Set Value",font=("arial",20),command=SetHighLimit)
highset.place(x=350, y=160,height=40,width=150)

control.mainloop()