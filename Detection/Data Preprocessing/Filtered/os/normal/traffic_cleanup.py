from scapy.all import *
from netml.pparser.parser import PCAP
import pandas as pd
import numpy as np

files = ['normal1','normal2','normal3','normal4','normal5']

for file in files:
    print("Processing : "+file)
    csv = pd.read_csv(file+'.csv').to_numpy()
    proto = pd.read_csv(file+'_proto.csv').to_numpy()
    for i in range(len(csv)):
        csv[i][13] = proto[i][4]

    csv = np.concatenate((np.zeros((len(csv),2), dtype=str), csv), axis=1)
    csv = np.concatenate((csv,np.zeros((len(csv),1), dtype=int)), axis=1)
    csv = np.concatenate((csv,np.zeros((len(csv),1), dtype=int)), axis=1)

    netml = PCAP(file+'.pcap')
    netml.pcap2pandas()
    datetime = netml.df.to_numpy()
    for i in range(len(csv)):
        [date,time] = str(datetime[i,0]).split(' ')
        csv[i,0] = date
        csv[i,1] = time
        

    pd.DataFrame(csv).to_csv('output/'+file+'.csv', index=False)
