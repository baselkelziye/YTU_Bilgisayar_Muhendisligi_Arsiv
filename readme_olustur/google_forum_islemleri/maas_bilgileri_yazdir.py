import pandas as pd
url = 'https://docs.google.com/spreadsheets/d/e/2PACX-1vRrFDdxAdd9KjqQE8oEohHiovpgN7PpNgKhZeTyIiBwpwIW6tiD3n2P_0tKvIP3PFxZrcuqWDfkvieQ/pub?output=csv'  # Buraya dosyanızın URL'sini veya dosya yolunu koyun

df = pd.read_csv(url)

# '2024 Maaşı (Aylık net ortalama)' sütunundaki eksik değerleri doldur
df['2024 Maaşı (Aylık net ortalama)'] = df['2024 Maaşı (Aylık net ortalama)'].fillna(df['2023 Maaşı (Aylık net ortalama)'])

# 1-) Şirketlere göre 2023 ve 2024 ortalaması
company_avg = df.groupby('Şirket Adı')[['2023 Maaşı (Aylık net ortalama)', '2024 Maaşı (Aylık net ortalama)']].mean()

# 3-) Şirketlerin maaş artış oranları
company_avg['Maaş Artış Oranı (%)'] = ((company_avg['2024 Maaşı (Aylık net ortalama)'] - company_avg['2023 Maaşı (Aylık net ortalama)']) / company_avg['2023 Maaşı (Aylık net ortalama)']) * 100

# 2-) Genel 2023 ve 2024 ortalaması
general_avg = df[['2023 Maaşı (Aylık net ortalama)', '2024 Maaşı (Aylık net ortalama)']].mean()

# 4-) Genel maaş artış oranı
general_increase_rate = ((general_avg['2024 Maaşı (Aylık net ortalama)'] - general_avg['2023 Maaşı (Aylık net ortalama)']) / general_avg['2023 Maaşı (Aylık net ortalama)']) * 100


# Alana göre 2023 ve 2024 ortalaması
field_avg = df.groupby('Pozisyon Alanı')[['2023 Maaşı (Aylık net ortalama)', '2024 Maaşı (Aylık net ortalama)']].mean()

# Alana göre maaş artış oranları
field_avg['Maaş Artış Oranı (%)'] = ((field_avg['2024 Maaşı (Aylık net ortalama)'] - field_avg['2023 Maaşı (Aylık net ortalama)']) / field_avg['2023 Maaşı (Aylık net ortalama)']) * 100

# Tecrübe süresini sayısal bir değere dönüştüren fonksiyon
def tecrube_suresi_donustur(tecrube):
    if tecrube == '0 - 6 ay':
        return 0.5
    elif tecrube == '6 ay - 1 yıl':
        return 1
    elif tecrube == '1 yıl - 2 yıl':
        return 1.5
    elif tecrube == '2 yıl - 4 yıl':
        return 3
    elif tecrube == '4 yıl - 6 yıl':
        return 5
    else:
        return 0  # Belirsiz değerler için

# Tecrübe süresi sayısal değerine göre sıralama için bir sütun oluştur
df['Tecrübe Süresi Sayısal'] = df['Tecrübe Süresi'].apply(tecrube_suresi_donustur)

# Yeniden gruplama ve ortalamaları hesaplama
experience_avg = df.groupby('Tecrübe Süresi', as_index=False)[['2023 Maaşı (Aylık net ortalama)', '2024 Maaşı (Aylık net ortalama)']].mean()
experience_avg['Maaş Artış Oranı (%)'] = ((experience_avg['2024 Maaşı (Aylık net ortalama)'] - experience_avg['2023 Maaşı (Aylık net ortalama)']) / experience_avg['2023 Maaşı (Aylık net ortalama)']) * 100

# Tecrübe süresi sayısal değerine göre sıralama
experience_avg['Tecrübe Süresi Sayısal'] = experience_avg['Tecrübe Süresi'].apply(tecrube_suresi_donustur)
experience_avg = experience_avg.sort_values(by='Tecrübe Süresi Sayısal')

# Genel Maaş Ortalamaları ve Artış Oranı için Markdown tablosunu oluşturan kod
genel_maas_tablosu = """
| Ortalama Maaş (Aylık net ortalama) 2023 | Ortalama Maaş (Aylık net ortalama) 2024 | Maaş Artış Oranı (%) |
|----------------------------------------|----------------------------------------|----------------------|
| {ortalama_2023:.2f}                     | {ortalama_2024:.2f}                     | {artis_orani:.2f}    |
""".format(ortalama_2023=general_avg['2023 Maaşı (Aylık net ortalama)'],
           ortalama_2024=general_avg['2024 Maaşı (Aylık net ortalama)'],
           artis_orani=general_increase_rate)
print("\n#### Genel Maaş Ortalamaları ve Artış Oranı\n")
print(genel_maas_tablosu)


# Sonuçları Markdown formatında yazdıralım (sıralı tecrübe süresiyle)
print("\n\n\n#### Tecrübeye Göre Maaş Ortalamaları ve Artış Oranları\n")
print(experience_avg[['Tecrübe Süresi', '2023 Maaşı (Aylık net ortalama)', '2024 Maaşı (Aylık net ortalama)', 'Maaş Artış Oranı (%)']].to_markdown(index=False))

# Markdown formatında alana göre maaş ortalamaları ve artış oranlarını yazdıralım
print("\n\n\n#### Alana Göre Maaş Ortalamaları ve Artış Oranları\n")
print(field_avg.to_markdown())


# Şimdi Markdown formatında sonuçları yazdıralım
print("\n\n\n#### Şirketlere Göre Maaş Ortalamaları ve Artış Oranları\n")
print(company_avg.to_markdown())