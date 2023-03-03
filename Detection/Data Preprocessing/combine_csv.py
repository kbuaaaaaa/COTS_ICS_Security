import glob
import pandas as pd
import numpy as np

pd.set_option('display.max_rows', None)
# files = ['arp','combination','injection','readbomb','recon','synflood']
files = ['malware']
for fname in files:
    file = glob.glob("training/"+fname+"/*.csv")
    combined_csv = pd.concat([pd.read_csv(f) for f in file ])
    combined_csv = combined_csv.sort_values(['date', 'time'], ascending=[True, True])
    print(combined_csv)
    combined_csv.to_csv( "testsets/"+fname+"2.csv", index=False, encoding='utf-8-sig')