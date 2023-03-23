import pandas as pd
import numpy as np
import glob

files = ['arp','combination','injection','readbomb','recon','synflood']
for file in files:
    data = pd.read_csv('normal/'+file+'.csv')
    date = data['date']
    data = data.drop(['date','ip.dsfield','ip.frag_offset','ip.version','eth.type','ip.hdr_len','raw'], axis = 1)
    col = data.columns
    data = data.to_numpy()
    for i in range(data.shape[0]):
        data[i,0] = str(date[i])+str(data[i,0])
    timestamps = sorted(np.unique(data[:,0]))
    for i in range(len(data[:,0])):
        print(i)
        data[i,0] = timestamps.index(data[i,0])
    data = pd.DataFrame(data)
    data.columns = col
    data = data.sort_values(['time'], ascending=[True])
    data.to_csv('testsets/raw_'+file+'.csv', index=False)