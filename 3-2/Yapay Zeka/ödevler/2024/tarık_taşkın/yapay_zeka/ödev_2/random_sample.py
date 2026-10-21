import pandas as pd

# Excel dosyasını oku
df = pd.read_excel('13k.xlsx')

# Başlık satırını koruyarak geri kalan satırlardan rastgele 1000 tanesini seç
df_sampled = df.iloc[1:].sample(n=100, random_state=42)
df_sampled.columns = df.columns  # Başlıkları koru
df_sampled.to_excel('1k.xlsx', index=False)