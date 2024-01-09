import pandas as pd
def csv_kontrol_et(df, kontrol_edilecek_elemanlar):
    is_valid = True
    # DataFrame sütun başlıklarını al
    df_basliklar = df.columns

    # Kontrol et
    for eleman in kontrol_edilecek_elemanlar:
        if eleman not in df_basliklar:
            print(f"Hata: '{eleman}' DataFrame'de bir başlık değil.")
            is_valid = False
    return is_valid