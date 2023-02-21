import glob
import pandas as pd
import numpy as np
csv = pd.read_csv('training_set.csv').to_numpy()
normal = 0
attack = 0
for row in csv:
    if row[-1] == 1:
        attack+=1
    else:
        normal+=1

print("Attack : "+str(attack)+"\nNormal : "+str(normal))