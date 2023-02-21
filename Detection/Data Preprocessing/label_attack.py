import pandas as pd
import glob
import numpy as np

# "2023/02/16"
dayone = [["10:45:00","11:16:00"],
          ["12:35:00","13:06:00"],
          ["13:45:00","14:16:00"],
          ["14:55:00","15:26:00"],
          ["20:00:00","20:31:00"]]
# "2023/02/17"
daytwo = [["10:05:00","10:21:00"],
          ["10:55:00","11:11:00"],
          ["11:45:00","12:01:00"],
          ["12:35:00","12:51:00"],
          ["13:25:00","13:41:00"],
          ["14:15:00","14:46:00"]]

output = np.array([['date','time','eth.src','eth.dst','eth.type','ip.src',
                    'ip.dst','ip.version','ip.hdr_len','ip.dsfield','ip.len',
                    'ip.id','ip.flags','ip.frag_offset','ip.ttl','ip.proto','tcp.srcport',
                    'tcp.dstport','tcp.seq','tcp.ack','tcp.hdr_len','tcp.flags','tcp.window_size',
                    'tcp.time_delta','tcp.time_relative','raw','attack']])

attack = 0

files = glob.glob("output/*.csv")


for file in files:
    print('processing '+file)
    csv = pd.read_csv(file).to_numpy()
    csv = np.append(csv,[[0]]*len(csv), axis=1)
    for row in csv:
        print("Processsing "+row[0]+" "+row[1])
        if row[0] == "16/02/2023":
            for time in dayone:
                if row[1] >= time[0] and row[1] <= time[1]:
                    print("Attack found")
                    row[-1] = 1
        elif row[0] == "17/02/2023":
             for time in daytwo:
                if row[1] >= time[0] and row[1] <= time[1]:
                    print("Attack found")
                    row[-1] = 1  
        output = np.append(output,[row],axis = 0)
    to_file = pd.DataFrame(output)
    to_file.to_csv("labeled/"+file, index=False)

# print("Attacks : " + attack + "\nNormal : " + len(output)-attack)
# output = output[np.lexsort((output[:,0], output[:,1]))]
