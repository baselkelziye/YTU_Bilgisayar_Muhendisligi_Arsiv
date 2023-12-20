import pandas as pd
import json
import os

# Google Sheets dosyasının URL'si
sheets_url = "https://docs.google.com/spreadsheets/d/1w386auUiJaGwoUAmmkEgDtIRSeUplmDz0AZkM09xPTk/export?format=csv"

# Veriyi indir ve DataFrame olarak oku
df = pd.read_csv(sheets_url)


# Sadece sayısal sütunları al ve ortalama hesapla
numeric_columns = df.columns.drop(['Zaman damgası', 'Hoca seç'])  # Sayısal olmayan sütunları çıkar
grouped = df.groupby('Hoca seç')[numeric_columns].mean()


# JSON dosyasını oku
json_file_path = 'hocalar.json'  # JSON dosyasının yolu
with open(os.path.join('..',json_file_path), 'r', encoding='utf-8') as file:
    data = json.load(file)
for hoca in data['hocalar']:
    name = hoca.get('ad')
    if name in grouped.index:
        hoca['anlatim_puani'] = int(grouped.loc[name, 'Dersi ne kadar güzel anlatır?'] * 10)
        hoca['kolaylik_puani'] = int(grouped.loc[name, 'Dersini geçmek ne kadar kolaydır?'] * 10)
        hoca['ogretme_puani'] = int(grouped.loc[name, 'Dersi ne kadar iyi öğretir?'] * 10)
        hoca['eglence_puani'] = int(grouped.loc[name, 'Dersi ne kadar eğlenceli anlatır?'] * 10)

with open(json_file_path, 'w', encoding='utf-8') as file:
    json.dump(data, file, indent=4)
