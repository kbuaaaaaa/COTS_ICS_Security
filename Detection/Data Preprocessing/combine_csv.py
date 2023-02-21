import glob
import pandas as pd
import numpy as np
# pd.set_option('display.max_rows', None)
# files = glob.glob("Labeled/*.csv")
# combined_csv = pd.concat([pd.read_csv(f) for f in files ])
# print(combined_csv)
# combined_csv = combined_csv.sort_values(['date', 'time'], ascending=[True, True])
# combined_csv.to_csv( "training_set.csv", index=False, encoding='utf-8-sig')

trainset = pd.read_csv('training_set.csv').to_numpy()
for row in trainset:
    print(row[0]+" "+row[1])