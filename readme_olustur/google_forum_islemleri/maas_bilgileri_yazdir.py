import pandas as pd

url = "https://docs.google.com/spreadsheets/d/e/2PACX-1vRrFDdxAdd9KjqQE8oEohHiovpgN7PpNgKhZeTyIiBwpwIW6tiD3n2P_0tKvIP3PFxZrcuqWDfkvieQ/pub?output=csv"  # Buraya dosyanızın URL'sini veya dosya yolunu koyun

df = pd.read_csv(url)


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
        return 0  # Belirsiz değerler için


def filter_func(x):
    return len(x) > 1


def dfOnIsle(df, startIndex=0, endIndex=1):
    df = df.round(2).fillna("Bilgi Yok")

    for i in range(startIndex, endIndex + 1):
        for j in range(len(df)):
            try:
                df.iloc[j, i] = int(df.iloc[j, i])
            except ValueError:
                pass  # Metinsel değerler olduğunda hata oluşacak, bu durumda hiçbir şey yapma

    return df


# Çalışma Durumuna göre veriyi grupla ve analiz et
for durum in df["Çalışma Durumu"].unique():
    durum_df = df[df["Çalışma Durumu"] == durum].copy()
    for mezuniyet in durum_df["Mezun Musunuz"].unique():
        # Mezun Musunuz sütununa göre daha da filtrele
        mezuniyet_df = durum_df[durum_df["Mezun Musunuz"] == mezuniyet].copy()
        if mezuniyet_df.empty:
            continue  # Eğer filtrelenmiş DataFrame boşsa, bu iterasyonu atla
        mezuniyet = "Mezun" if mezuniyet == "Evet" else "Mezun Değil"
        print(f"\n### {durum} ve {mezuniyet} için Maaş Analizi\n")
        # Şirketlere göre 2023 ve 2024 ortalaması ve maaş artış oranları
        # Şirket adına göre gruplandır ve yalnızca birden fazla veri noktası olanları filtrele
        filtered_company_avg = mezuniyet_df.groupby(mezuniyet_df.columns[7]).filter(
            filter_func
        )

        # Şimdi filtrelenmiş gruplar üzerinde ortalama ve maaş artış oranını hesapla
        company_avg = filtered_company_avg.groupby(filtered_company_avg.columns[7])[
            [filtered_company_avg.columns[4], filtered_company_avg.columns[5]]
        ].mean()
        company_avg["Maaş Artış Oranı (%)"] = (
            (company_avg[company_avg.columns[1]] - company_avg[company_avg.columns[0]])
            / company_avg[company_avg.columns[0]]
        ) * 100

        # Genel 2023 ve 2024 ortalaması ve genel maaş artış oranı
        general_avg = mezuniyet_df[
            [mezuniyet_df.columns[4], mezuniyet_df.columns[5]]
        ].mean()
        general_increase_rate = (
            (general_avg[1] - general_avg[0]) / general_avg[0]
        ) * 100

        # Alana ve tecrübeye göre maaş analizleri
        field_avg = mezuniyet_df.groupby(mezuniyet_df.columns[2])[
            [mezuniyet_df.columns[4], mezuniyet_df.columns[5]]
        ].mean()
        field_avg["Maaş Artış Oranı (%)"] = (
            (field_avg[field_avg.columns[1]] - field_avg[field_avg.columns[0]])
            / field_avg[field_avg.columns[0]]
        ) * 100
        mezuniyet_df["Tecrübe Süresi Sayısal"] = mezuniyet_df[
            mezuniyet_df.columns[3]
        ].apply(tecrube_suresi_donustur)
        experience_avg = mezuniyet_df.groupby(mezuniyet_df.columns[3], as_index=False)[
            [mezuniyet_df.columns[4], mezuniyet_df.columns[5]]
        ].mean()
        # Kolon indekslerini kullanarak Maaş Artış Oranı (%) hesaplama
        experience_avg["Maaş Artış Oranı (%)"] = (
            (
                experience_avg[experience_avg.columns[2]]
                - experience_avg[experience_avg.columns[1]]
            )
            / experience_avg[experience_avg.columns[1]]
        ) * 100
        experience_avg["Tecrübe Süresi Sayısal"] = experience_avg[
            experience_avg.columns[0]
        ].apply(tecrube_suresi_donustur)
        experience_avg = experience_avg.sort_values(by="Tecrübe Süresi Sayısal")

        if not general_avg.isnull().all():
            genel_maas_tablosu = """
| Ortalama Maaş (Aylık net ortalama) 2023 | Ortalama Maaş (Aylık net ortalama) 2024 | Maaş Artış Oranı (%) |
|----------------------------------------|----------------------------------------|----------------------|
| {:.0f}                                 | {:.0f}                                 | {:.2f}               |
            """.format(
                general_avg[0], general_avg[1], general_increase_rate
            ).strip()
            print("\n##### Genel Maaş Ortalamaları ve Artış Oranı\n")
            print(genel_maas_tablosu)
        # Şimdi Markdown formatında sonuçları yazdıralım (eğer boş değilse)
        if not company_avg.empty:
            company_avg = dfOnIsle(company_avg)
            print("\n\n\n##### Şirketlere Göre Maaş Ortalamaları ve Artış Oranları\n")
            print(company_avg.to_markdown())
        if not field_avg.empty:
            field_avg = dfOnIsle(field_avg)
            print("\n\n\n##### Alana Göre Maaş Ortalamaları ve Artış Oranları\n")
            print(field_avg.to_markdown())

        if not experience_avg.empty:
            experience_avg = experience_avg.drop(experience_avg.columns[-1], axis=1)
            experience_avg = dfOnIsle(experience_avg, 1, 2)
            print("\n\n\n##### Tecrübeye Göre Maaş Ortalamaları ve Artış Oranları\n")
            print(experience_avg.to_markdown(index=False))

# Ankete katılan kişi sayısını hesapla
katilan_kisi_sayisi = len(df)

# Katılan kişi sayısını yazdır
print(f"\nℹ️  Anket sonuçları: {katilan_kisi_sayisi} kişi üzerinden hesaplanmıştır.")
