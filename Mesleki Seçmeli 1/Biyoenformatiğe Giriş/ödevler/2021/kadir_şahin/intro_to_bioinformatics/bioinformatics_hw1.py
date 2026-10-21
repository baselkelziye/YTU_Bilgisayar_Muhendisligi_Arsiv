import matplotlib.pyplot as plt
import numpy as np 
import pandas as pd


input_genes = pd.read_table("C:/YOURFULLDIRECTORY/psoriasis_10genes.txt")

stats=pd.DataFrame()

stats['[Mean]'] = input_genes.apply(np.mean,axis=1)
stats['[SD]'] = input_genes.apply(np.std,axis=1)
stats['[CV]'] = stats['[SD]']/stats['[Mean]']


print(stats)
print("\n")

stats.sort_values(by='[CV]',axis=0,ascending=False,inplace=True,kind='quicksort')

print(stats) #for index,rows in input_genes:




