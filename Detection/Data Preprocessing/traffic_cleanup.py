from scapy.all import *
from netml.pparser.parser import PCAP
import pandas as pd
import numpy as np

files = ['arp_poisoning','arp_reversetcp','bypassuac','injection',
        'mysterysnail','pn+bs+ms','printnightmare','readbomb',
        'readbomb+injection','recon','synflood']

for file in files:
    print("Processing : "+file)
    csv = pd.read_csv('training/'+file+'.csv').to_numpy()
    proto = pd.read_csv('training/'+file+'_proto.csv').to_numpy()
    for i in range(len(csv)):
        csv[i][13] = proto[i][4]

    csv = np.concatenate((np.zeros((len(csv),2), dtype=str), csv), axis=1)
    csv = np.concatenate((csv,np.zeros((len(csv),1), dtype=int)), axis=1)
    csv = np.concatenate((csv,np.zeros((len(csv),1), dtype=int)), axis=1)

    netml = PCAP('training/'+file+'.pcap')
    netml.pcap2pandas()
    datetime = netml.df.to_numpy()
    for i in range(len(csv)):
        [date,time] = str(datetime[i,0]).split(' ')
        csv[i,0] = date
        csv[i,1] = time
        
    scapydf = rdpcap('training/'+file+'.pcap')
    for i in range(len(csv)):
        if csv[i,15] == 'Modbus/TCP':
            if Raw in scapydf[i]:
                csv[i,-2] = int(scapydf[i][Raw].load[2:].hex(), 16)
            else :
                csv[i,-2] = 0
        else :
            csv[i,-2] = 0

    pd.DataFrame(csv).to_csv('output/'+file+'.csv', index=False)
