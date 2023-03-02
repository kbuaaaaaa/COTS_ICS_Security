import pandas as pd
import numpy as np
import glob

files = glob.glob("*.csv")
files = ['normal1.csv']
for file in files:
    csv = pd.read_csv(file).to_numpy()
    rem = np.random.choice([False, True], len(csv), p=[0.80, 0.20])
    csv = csv[rem]
    pd.DataFrame(csv).to_csv(file, index=False)
