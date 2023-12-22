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
def sirala_ve_ayir(hocalar_listesi):
    """
    Hocaların adlarını, ünvanlarına göre önceliklendirilmiş bir sırayla sıralar.
    Önce 'Prof. Dr.', sonra 'Doç. Dr.', ardından 'Dr.' ve son olarak ünvanı olmayanları sıralar.
    """
    # Unvanlara öncelik değerleri atayalım.
    unvanlar = {
        "Prof. Dr.": 1,
        "Prof.": 1,
        "Doç. Dr.": 2,
        "Doç.": 2,
        "Dr.": 3
    }

    def unvan_önceligi(hoca_adi):
        # Hocanın adındaki unvanı bul ve öncelik değerini döndür
        for unvan, öncelik in unvanlar.items():
            if hoca_adi.startswith(unvan):
                return öncelik
        # Eğer hiçbir unvan eşleşmiyorsa, varsayılan olarak en düşük önceliği (en yüksek sayıyı) ver
        return max(unvanlar.values()) + 1

    # Hocaların adlarını önceliklere göre ve alfabetik sıraya göre sırala
    sirali_hocalar = sorted(hocalar_listesi, key=lambda hoca: (unvan_önceligi(hoca), hoca))
    return sirali_hocalar

# Hoca adlarını işle ve unvanları at
hoca_names = [hoca['ad'] for hoca in data['hocalar']]
hoca_names = sirala_ve_ayir(hoca_names)
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
