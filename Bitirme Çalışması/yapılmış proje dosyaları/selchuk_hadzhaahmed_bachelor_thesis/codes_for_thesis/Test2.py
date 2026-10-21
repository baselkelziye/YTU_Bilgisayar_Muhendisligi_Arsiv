import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import csv

dataset = pd.read_csv('CompleteDataset1.csv')

dataReal = dataset.loc[dataset.Club.str.contains('Real Madrid CF') == True, "Club"]
dataBayern = dataset.loc[dataset.Club.str.contains('Bayern Munich') == True, "Club"]
dataJuve = dataset.loc[dataset.Club.str.contains('Juventus') == True, "Club"]
dataCity = dataset.loc[dataset.Club.str.contains('Manchester City') == True, "Club"]
dataPSG = dataset.loc[dataset.Club.str.contains('Paris Saint-Germain') == True, "Club"]
dataGS = dataset.loc[dataset.Club.str.contains('Galatasaray') == True, "Club"]


print(dataGS)
