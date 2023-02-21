from scapy.all import *
from netml.pparser.parser import PCAP
import pandas as pd
import numpy as np

files = ['evaluation','normal_traffic3','normal_traffic4','normal_traffic5']

for file in files:
    csv = pd.read_csv('pcap/'+file+'.csv').to_numpy()
    proto = pd.read_csv('pcap/proto_'+file+'.csv').to_numpy()
    for i in range(len(csv)):
        csv[i][13] = proto[i][4]

    csv = np.concatenate((np.zeros((len(csv),2), dtype=str), csv), axis=1)
    csv = np.concatenate((csv,np.zeros((len(csv),1), dtype=str)), axis=1)
    csv = np.concatenate((csv,np.zeros((len(csv),1), dtype=int)), axis=1)

    netml = PCAP('pcap/'+file+'.pcap')
    netml.pcap2pandas()
    datetime = netml.df.to_numpy()
    for i in range(len(csv)):
        [date,time] = str(datetime[i,0]).split(' ')
        csv[i,0] = date
        csv[i,1] = time
        
    scapydf = rdpcap('pcap/'+file+'.pcap')
    for i in range(len(csv)):
        if csv[i,15] == 'Modbus/TCP':
            if Raw in scapydf[i]:
                csv[i,-2] = scapydf[i][Raw].load[2:].hex()
            else :
                csv[i,-2] = 0
        else :
            csv[i,-2] = 0

    pd.DataFrame(csv).to_csv('output/'+file+'.csv', index=False)
