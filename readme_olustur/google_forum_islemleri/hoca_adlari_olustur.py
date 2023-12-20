import json
import csv

"""
    Google forumlar için hoca adları csv dosyası oluşturur.
"""


# Dosya yolu
json_file_path = '../hocalar.json'  # JSON dosyasının yolu

# JSON dosyasını oku
with open(json_file_path, 'r', encoding='utf-8') as file:
    data = json.load(file)

# Hocaların adlarını bir liste olarak al
hoca_names = [hoca['ad'] for hoca in data['hocalar']]

# CSV dosyası oluştur
csv_file_path = 'hoca_listesi.csv'  # Oluşturulacak CSV dosyasının yolu
with open(csv_file_path, 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    # Sütun başlığını yaz
    writer.writerow(['Hoca Adı'])
    # Her hocanın adını yaz
    for name in hoca_names:
        if name:
            writer.writerow([name])
