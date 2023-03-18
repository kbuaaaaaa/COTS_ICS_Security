import glob
import pandas as pd
import numpy as np

pd.set_option('display.max_rows', None)
# files = ['arp','combination','injection','readbomb','recon','synflood']
files = ['ics_normal']
for f in files:
    print(f)
    temp = glob.glob("training/"+f+"/*.csv")
    combined_csv = pd.concat([pd.read_csv(t) for t in temp ])
    combined_csv = combined_csv.sort_values(['date', 'time'], ascending=[True, True])
    combined_csv.to_csv( "testsets/"+f+".csv", index=False, encoding='utf-8-sig')