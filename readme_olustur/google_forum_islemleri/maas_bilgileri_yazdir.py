import io
import sys
import pandas as pd
import pyperclip

# Sütun indeksleri
I_ZAMAN       = 0
I_MEZUN       = 1
I_CALISIYOR   = 2
I_TURKIYE     = 3
I_POZISYON    = 4
I_OKUL        = 5
I_SIRKET      = 6
I_CALISMA_DUR = 7
I_TECRUBE     = 8
ESKI_MAAS     = 9
ZAMLI_MAAS    = 10


def veri_yukle(url: str) -> pd.DataFrame:
    df = pd.read_csv(url)
    eski_col = df.columns[ESKI_MAAS]
    yeni_col = df.columns[ZAMLI_MAAS]
    # Yeni yıl maaşı girilmemişse eski yıl maaşını kullan
    df[yeni_col] = df[yeni_col].fillna(df[eski_col])
    return df



def artis_orani_hesapla(df: pd.DataFrame, eski_col: str, yeni_col: str) -> pd.Series:
    # Yüzdelik artış: (yeni - eski) / eski * 100
    return (df[yeni_col] - df[eski_col]) / df[eski_col] * 100


def temizle(df: pd.DataFrame, maas_kolonlari: list) -> pd.DataFrame:
    df = df.round(2)
    # Maaş kolonları sayısal kalmalı, sadece grup/index kolonlarındaki NaN'ları "bilinmiyor" yap
    non_maas = [c for c in df.columns if c not in maas_kolonlari]
    df[non_maas] = df[non_maas].astype(object).fillna("bilinmiyor")
    return df


def issizlik_oranlarini_yazdir(df: pd.DataFrame) -> None:
    # Mezuniyet durumuna göre alt kümeler
    mezun_df = df[df.iloc[:, I_MEZUN] == "Evet"]
    mezun_calismayan_df = mezun_df[mezun_df.iloc[:, I_CALISIYOR] == "Hayır"]
    mezun_olmayan_df = df[df.iloc[:, I_MEZUN] == "Hayır"]
    mezun_olmayan_calismayan_df = mezun_olmayan_df[mezun_olmayan_df.iloc[:, I_CALISIYOR] == "Hayır"]

    # Oranlar; bölme hatasını önlemek için sıfır kontrolü yap
    mezun_issiz_orani = len(mezun_calismayan_df) / len(mezun_df) * 100 if len(mezun_df) > 0 else 0
    mezun_olmayan_issiz_orani = len(mezun_olmayan_calismayan_df) / len(mezun_olmayan_df) * 100 if len(mezun_olmayan_df) > 0 else 0
    # Yurt dışında çalışanlar / tüm çalışanlar
    yurtdisi_orani = len(df[df.iloc[:, I_TURKIYE] == "Evet"]) / len(df[df.iloc[:, I_CALISIYOR] == "Evet"]) * 100

    print(f"""
| **Durum**                        | **Oran (%)**       |
|----------------------------------|--------------------| 
| Mezunların % kaçı işsiz               | %{mezun_issiz_orani:.2f} |
| Mezun olmayanların % kaçı işsiz       | %{mezun_olmayan_issiz_orani:.2f} |
| Yurt dışında çalışmayanların oranı    | %{yurtdisi_orani:.2f} |
""")


def sirket_analizi(mezuniyet_df: pd.DataFrame, eski_col: str, yeni_col: str) -> pd.DataFrame | None:
    df = mezuniyet_df.dropna(subset=[eski_col, yeni_col])
    # Tek kişilik şirketleri anlamsız ortalama vermemesi için dışla
    filtered = df.groupby(df.columns[I_SIRKET]).filter(lambda x: len(x) > 1)
    if filtered.empty:
        return None
    avg = filtered.groupby(filtered.columns[I_SIRKET])[[eski_col, yeni_col]].mean()
    avg["Maaş Artış Oranı (%)"] = artis_orani_hesapla(avg, eski_col, yeni_col)
    return temizle(avg, [eski_col, yeni_col, "Maaş Artış Oranı (%)"])


def alan_analizi(mezuniyet_df: pd.DataFrame, eski_col: str, yeni_col: str) -> pd.DataFrame:
    df = mezuniyet_df.dropna(subset=[eski_col, yeni_col])
    if df.empty:
        return df
    avg = df.groupby(df.columns[I_POZISYON])[[eski_col, yeni_col]].mean()
    avg["Maaş Artış Oranı (%)"] = artis_orani_hesapla(avg, eski_col, yeni_col)
    return temizle(avg, [eski_col, yeni_col, "Maaş Artış Oranı (%)"])


def tecrube_analizi(mezuniyet_df: pd.DataFrame, eski_col: str, yeni_col: str) -> pd.DataFrame:
    df = mezuniyet_df.dropna(subset=[eski_col, yeni_col]).copy()
    if df.empty:
        return df
    avg = df.groupby(df.columns[I_TECRUBE], as_index=False)[[eski_col, yeni_col]].mean()
    avg["Maaş Artış Oranı (%)"] = artis_orani_hesapla(avg, eski_col, yeni_col)
    return temizle(avg, [eski_col, yeni_col, "Maaş Artış Oranı (%)"])


def genel_analizi_yazdir(mezuniyet_df: pd.DataFrame, eski_col: str, yeni_col: str, eski_yil: int, yeni_yil: int) -> None:
    general_avg = mezuniyet_df[[eski_col, yeni_col]].mean()
    # Her iki yıl verisi de yoksa tabloyu yazdırma
    if general_avg.isnull().any():
        return
    artis = (general_avg.iloc[1] - general_avg.iloc[0]) / general_avg.iloc[0] * 100
    print(f"\n##### Genel Maaş Ortalamaları ({eski_yil}–{yeni_yil}) ve Artış Oranı\n")
    print(f"| Ortalama Maaş {eski_yil} | Ortalama Maaş {yeni_yil} | Maaş Artış Oranı (%) |")
    print(f"|-------------------|--------------------|-----------------------|")
    print(f"| {int(general_avg.iloc[0])}              | {int(general_avg.iloc[1])}              | {artis:.2f}                |")


def maas_analizini_yazdir(df: pd.DataFrame, eski_yil: int, yeni_yil: int) -> None:
    eski_col = df.columns[ESKI_MAAS]
    yeni_col = df.columns[ZAMLI_MAAS]

    # Her çalışma durumu (tam zamanlı, stajyer vb.) için ayrı analiz
    for durum in df.iloc[:, I_CALISMA_DUR].unique():
        durum_df = df[df.iloc[:, I_CALISMA_DUR] == durum].copy()

        # Her çalışma durumu içinde mezun/mezun değil ayrımı
        for mezuniyet in durum_df.iloc[:, I_MEZUN].unique():
            mezuniyet_df = durum_df[durum_df.iloc[:, I_MEZUN] == mezuniyet].copy()
            if mezuniyet_df.empty:
                continue

            mezun_text = "Mezun" if mezuniyet == "Evet" else "Mezun Değil"
            print(f"\n### {durum} ve {mezun_text} için Maaş Analizi\n")

            genel_analizi_yazdir(mezuniyet_df, eski_col, yeni_col, eski_yil, yeni_yil)

            # Şirket bazlı analiz (en az 2 kişi olan şirketler)
            company_avg = sirket_analizi(mezuniyet_df, eski_col, yeni_col)
            if company_avg is not None:
                print(f"\n\n\n##### Şirketlere Göre Maaş Ortalamaları ve Artış Oranları ({eski_yil}–{yeni_yil})\n")
                print(company_avg.to_markdown())

            # Pozisyon alanı bazlı analiz
            field_avg = alan_analizi(mezuniyet_df, eski_col, yeni_col)
            if not field_avg.empty:
                print(f"\n\n\n##### Alana Göre Maaş Ortalamaları ve Artış Oranları ({eski_yil}–{yeni_yil})\n")
                print(field_avg.to_markdown())

            # Tecrübe süresi bazlı analiz
            exp_avg = tecrube_analizi(mezuniyet_df, eski_col, yeni_col)
            if not exp_avg.empty:
                print(f"\n\n\n##### Tecrübeye Göre Maaş Ortalamaları ve Artış Oranları ({eski_yil}–{yeni_yil})\n")
                print(exp_avg.to_markdown(index=False))


def katilimci_sayisini_yazdir(df: pd.DataFrame, yeni_yil: int, eski_yil: int) -> None:
    print(f"\nℹ️  Anket sonuçları: {len(df.dropna(how='all'))} kişi üzerinden hesaplanmıştır. {yeni_yil} maaş bilgisi verilmeyen kayıtlarda {yeni_yil} maaşı sütununda {eski_yil} maaş bilgileri kullanılmıştır.")


def main(eski_yil: int = 2024, yeni_yil: int = 2025) -> None:
    url = "url"
    df = veri_yukle(url)

    # Tüm çıktıyı buffer'a al, sonra hem yazdır hem panoya kopyala
    buffer = io.StringIO()
    sys.stdout = buffer

    issizlik_oranlarini_yazdir(df)
    maas_analizini_yazdir(df, eski_yil, yeni_yil)
    katilimci_sayisini_yazdir(df, yeni_yil, eski_yil)

    sys.stdout = sys.__stdout__
    cikti = buffer.getvalue()
    print(cikti)
    pyperclip.copy(cikti)
    print("\n✅ Çıktı panoya kopyalandı.")


if __name__ == "__main__":
    main(eski_yil=2024, yeni_yil=2025)
