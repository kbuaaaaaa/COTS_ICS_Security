import glob
import pandas as pd
import numpy as np

pd.set_option('display.max_rows', None)
files = glob.glob("training/os/*.csv")
combined_csv = pd.concat([pd.read_csv(f) for f in files ])
combined_csv = combined_csv.sort_values(['date', 'time'], ascending=[True, True])
print(combined_csv)
combined_csv.to_csv( "os_training_time.csv", index=True, encoding='utf-8-sig')