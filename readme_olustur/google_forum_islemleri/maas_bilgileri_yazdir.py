import pandas as pd

pd.set_option('future.no_silent_downcasting', True)
# 1) Veriyi linkten okuma
url = "https://docs.google.com/spreadsheets/d/e/2PACX--WhA-eNoJZrK/pub?output=csv"
df = pd.read_csv(url)

# Yeni anket dosyasında sütunların iloc indekslerine göre anlamları:
#  0 -> Zaman damgası
#  1 -> Mezun Musunuz? (Evet/Hayır)
#  2 -> Çalışıyor musunuz? (Evet/Hayır)
#  3 -> Türkiye'de mi çalışıyorsunuz? (Evet/Hayır)
#  4 -> Pozisyon Alanı
#  5 -> Okul
#  6 -> Şirket Adı
#  7 -> Çalışma Durumu
#  8 -> Tecrübe Süresi
#  9 -> 2024 Maaşı (Aylık net ortalama)
# 10 -> 2025 Maaşı (Aylık net ortalama)

###############################################################################
# ÖNCE GENELDE MEZUN OLANLAR VE OLMAYANLAR İÇİN İŞSİZLİK ORANLARINI HESAPLAMA #
###############################################################################
mezun_df = df[df.iloc[:, 1] == "Evet"]  # Mezun olanlar
mezun_calismayan_df = mezun_df[mezun_df.iloc[:, 2] == "Hayır"]  # Mezun olup çalışmayan
mezun_olmayan_df = df[df.iloc[:, 1] == "Hayır"]  # Mezun olmayanlar
mezun_olmayan_calismayan_df = mezun_olmayan_df[mezun_olmayan_df.iloc[:, 2] == "Hayır"]

# 2) mezun_calismayan_orani = (Mezun olup çalışmayan / Tüm mezunlar) * 100
if len(mezun_df) > 0:
    mezun_calismayan_orani = len(mezun_calismayan_df) / len(mezun_df) * 100
else:
    mezun_calismayan_orani = 0

# 3) mezun_olmayan_calisma_orani = (Mezun olmayıp çalışmayan / Mezun olmayanların tamamı) * 100
if len(mezun_olmayan_df) > 0:
    mezun_olmayan_calisma_orani = len(mezun_olmayan_calismayan_df) / len(mezun_olmayan_df) * 100
else:
    mezun_olmayan_calisma_orani = 0
# 4) Yurt dışında çalışma oranı
yurtdisi_calisan_orani = len(df[df.iloc[:, 3] == "Evet"]) / len(df[df.iloc[:,2] == "Evet"]) * 100

markdown_tablo = f"""
| **Durum**                        | **Oran (%)**       |
|----------------------------------|--------------------|
| Mezunların % kaçı işsiz               | %{mezun_calismayan_orani:.2f} |
| Mezun olmayanların % kaçı işsiz       | %{mezun_olmayan_calisma_orani:.2f} |
| Yurt dışında çalışmayanların oranı    | %{yurtdisi_calisan_orani:.2f} |
"""
# Markdown tablosunu yazdır
print(markdown_tablo)

############################################################################
# Eski kod iskeleti koruyarak maaş analizlerini 2024–2025 verileriyle yapma #
############################################################################

# Tecrübe süresini sayısal bir değere dönüştüren fonksiyon
def tecrube_suresi_donustur(tecrube):
    if tecrube == "0 - 6 ay":
        return 0.5
    elif tecrube == "6 ay - 1 yıl":
        return 1
    elif tecrube == "1 yıl - 2 yıl":
        return 1.5
    elif tecrube == "2 yıl - 4 yıl":
        return 3
    elif tecrube == "4 yıl - 6 yıl":
        return 5
    else:
        return 0  # Belirsiz değerler için tutalım

# Filtre fonksiyonu (grup sayısı 1'den büyükse alalım)
def filter_func(x):
    return len(x) > 1

# Çalışma Durumuna göre veriyi grupla ve analiz et
for durum in df.iloc[:, 7].unique():
    durum_df = df[df.iloc[:, 7] == durum].copy()

    # Mezun Musunuz? -> df.iloc[:, 1]
    for mezuniyet in durum_df.iloc[:, 1].unique():
        mezuniyet_df = durum_df[durum_df.iloc[:, 1] == mezuniyet].copy()
        if mezuniyet_df.empty:
            continue

        # Ekrana “Mezun” / “Mezun Değil” diye basılacak küçük değişiklik
        mezun_text = "Mezun" if mezuniyet == "Evet" else "Mezun Değil"
        print(f"\n### {durum} ve {mezun_text} için Maaş Analizi\n")

        # Şirket bazında ortalama maaş (2024, 2025) + artış oranı
        filtered_company_avg = mezuniyet_df.groupby(mezuniyet_df.columns[6]).filter(filter_func)
        if not filtered_company_avg.empty:
            company_avg = filtered_company_avg.groupby(filtered_company_avg.columns[6])[
                [filtered_company_avg.columns[9], filtered_company_avg.columns[10]]
            ].mean()
            company_avg["Maaş Artış Oranı (%)"] = (
                (company_avg[company_avg.columns[1]] - company_avg[company_avg.columns[0]])
                / company_avg[company_avg.columns[0]]
            ) * 100
        filtered_company_avg = filtered_company_avg.round(2)  # Virgülden sonra 2 basamak
        filtered_company_avg = filtered_company_avg.astype(object)
        filtered_company_avg.fillna("bilinmiyor", inplace=True)
        company_avg = company_avg.round(2)  # Virgülden sonra 2 basamak
        company_avg = company_avg.astype(object)
        company_avg.fillna("bilinmiyor", inplace=True)
        # Genel ortalama (2024, 2025) ve artış oranı
        general_avg = mezuniyet_df[
            [mezuniyet_df.columns[9], mezuniyet_df.columns[10]]
        ].mean()
        if general_avg.isnull().any():
            general_increase_rate = float('nan')
        else:
            general_increase_rate = (
                (general_avg.iloc[1] - general_avg.iloc[0]) / general_avg.iloc[0] * 100
            )

        # Alana göre maaş analizleri -> "Pozisyon Alanı" = df.iloc[:, 4]
        field_avg = mezuniyet_df.groupby(mezuniyet_df.columns[4])[
            [mezuniyet_df.columns[9], mezuniyet_df.columns[10]]
        ].mean()
        field_avg["Maaş Artış Oranı (%)"] = (
            (field_avg[field_avg.columns[1]] - field_avg[field_avg.columns[0]])
            / field_avg[field_avg.columns[0]]
        ) * 100
        field_avg = field_avg.round(2)  # Virgülden sonra 2 basamak
        field_avg = field_avg.astype(object)
        field_avg.fillna("bilinmiyor", inplace=True)

        # Tecrübe Süresi -> df.iloc[:, 8]
        mezuniyet_df["Tecrübe Süresi Sayısal"] = mezuniyet_df[mezuniyet_df.columns[8]].apply(tecrube_suresi_donustur)
        experience_avg = mezuniyet_df.groupby(mezuniyet_df.columns[8], as_index=False)[
            [mezuniyet_df.columns[9], mezuniyet_df.columns[10]]
        ].mean()
        experience_avg["Maaş Artış Oranı (%)"] = (
            (experience_avg[experience_avg.columns[2]] - experience_avg[experience_avg.columns[1]])
            / experience_avg[experience_avg.columns[1]]
        ) * 100
        experience_avg = experience_avg.round(2)  # Virgülden sonra 2 basamak
        experience_avg = experience_avg.astype(object)
        experience_avg.fillna("bilinmiyor", inplace=True)
        # Sonuçları yazdıralım
        if not pd.isnull(general_increase_rate):
            print("\n##### Genel Maaş Ortalamaları (2024–2025) ve Artış Oranı\n")
            print(f"| Ortalama Maaş 2024 | Ortalama Maaş 2025 | Maaş Artış Oranı (%) |")
            print(f"|-------------------|--------------------|-----------------------|")
            print(f"| {int(general_avg.iloc[0])}              | {int(general_avg.iloc[1])}              | {general_increase_rate:.2f}                |")

        if not filtered_company_avg.empty:
            print("\n\n\n##### Şirketlere Göre Maaş Ortalamaları ve Artış Oranları (2024–2025)\n")
            print(company_avg.to_markdown())

        if not field_avg.empty:
            print("\n\n\n##### Alana Göre Maaş Ortalamaları ve Artış Oranları (2024–2025)\n")
            print(field_avg.to_markdown())

        if not experience_avg.empty:
            print("\n\n\n##### Tecrübeye Göre Maaş Ortalamaları ve Artış Oranları (2024–2025)\n")
            print(experience_avg.to_markdown(index=False))

# Tüm satırları boş olanları filtrele
df_cleaned = df.dropna(how='all')

# Katılan kişi sayısını hesapla
katilan_kisi_sayisi = len(df_cleaned)

# Sonucu yazdır
print(f"\nℹ️  Anket sonuçları: {katilan_kisi_sayisi} kişi üzerinden hesaplanmıştır.")