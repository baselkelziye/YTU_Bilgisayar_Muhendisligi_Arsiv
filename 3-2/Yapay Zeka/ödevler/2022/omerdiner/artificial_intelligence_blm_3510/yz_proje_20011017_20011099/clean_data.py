import pandas as pd
import os
import re

def process_and_combine_excel_files(file_names, output_file):
    dataframes = []

    for file in file_names:
        # Excel dosyasını yükleyin
        df = pd.read_excel(file, header=None)

        # İkinci sütunu ekleyin ve tüm satırlara dosya adını atayın
        df['B'] = os.path.splitext(file)[0]

        # Başlık satırını ekleyin
        df.columns = ['Lyrics', 'Genre']

        # İlk satırı sil
        df = df.iloc[1:]

        # İlk 200 satırı tut sonra gerisini sil
        df = df.head(200)

        # DataFrame'i listeye ekleyin
        dataframes.append(df)

    # Tüm DataFrame'leri birleştirin
    combined_df = pd.concat(dataframes, ignore_index=True)

    # Birleştirilmiş DataFrame'i yeni bir Excel dosyasına kaydedin
    combined_df.to_excel(output_file, index=False)


def clean_excel_file(input_file, output_file):
    # Excel dosyasını oku
    df = pd.read_excel(input_file)

    # Parantez içindeki ve ** ** arasındaki ifadeleri kaldıran fonksiyon
    def remove_bracketed_text(text):
        text = re.sub(r'\(.*?\)', '', text)  # Parantez içindekiler
        text = re.sub(r'\*\*.*?\*\*', '', text)  # ** ** arasındakiler
        text = re.sub(r'\[.*?\]', '', text) # Köşeli parantez içindekiler
        return text

    # A sütunundaki her bir hücre için fonksiyonu uygula
    df['Lyrics'] = df['Lyrics'].apply(remove_bracketed_text)

    # Temizlenmiş verileri yeni bir Excel dosyasına kaydet
    df.to_excel(output_file, index=False)


if __name__ == "__main__":
    file_names = ['Rap.xlsx', 'Metal.xlsx', 'Rock.xlsx', 'Pop.xlsx', 'Country.xlsx']
    output_file = 'SyntheticData.xlsx'
    process_and_combine_excel_files(file_names, output_file)

    input_file = 'SyntheticData.xlsx'
    output_file = 'CleanedData.xlsx'
    clean_excel_file(input_file, output_file)
