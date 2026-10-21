import pandas as pd
import re

df = pd.read_csv('cleaned_test_lyrics.csv')

#ilk kolonu sil
df = df.drop(df.columns[0], axis=1)


#bu verileri excel dosyasına kaydet.
#ilk kolon adı Lyrics, ikinci kolon adı Genre olsun.
df.columns = ['Lyrics', 'Genre']


#5 tür var. her türden 100 satır al.
df = df.groupby('Genre').apply(lambda x: x.sample(150)).reset_index(drop=True)


# Parantez içindeki ve ** ** arasındaki ifadeleri kaldıran fonksiyon
def remove_bracketed_text(text):
    text = re.sub(r'\(.*?\)', '', text)  # Parantez içindekiler
    text = re.sub(r'\*\*.*?\*\*', '', text)  # ** ** arasındakiler
    text = re.sub(r'\[.*?\]', '', text)  # Köşeli parantez içindekiler
    return text

# A sütunundaki her bir hücre için fonksiyonu uygula
df['Lyrics'] = df['Lyrics'].apply(remove_bracketed_text)

# Genre sütuunda pop yazanları Pop yap
df['Genre'] = df['Genre'].apply(lambda x: 'Pop' if x == 'pop' else x)
# Genre sütuunda rock yazanları Rock yap
df['Genre'] = df['Genre'].apply(lambda x: 'Rock' if x == 'rock' else x)
# Genre sütuunda rap yazanları Rap yap
df['Genre'] = df['Genre'].apply(lambda x: 'Rap' if x == 'rap' else x)
# Genre sütuunda country yazanları Country yap
df['Genre'] = df['Genre'].apply(lambda x: 'Country' if x == 'country' else x)
# Genre sütuunda metal yazanları Metal yap
df['Genre'] = df['Genre'].apply(lambda x: 'Metal' if x == 'metal' else x)



#genreye göre sırala
df = df.sort_values(by='Genre')


df_pop= df[df['Genre'] == 'Pop']
df_rock= df[df['Genre'] == 'Rock']
df_rap= df[df['Genre'] == 'Rap']
df_country= df[df['Genre'] == 'Country']
df_metal= df[df['Genre'] == 'Metal']

#dfpopp , dfrock, dfrap, dfcountry, dfmetalin her birinin ilk 100 satırını al ve tek bir dataframe yap
df500 = pd.concat([df_rap.head(100), df_metal.head(100), df_rock.head(100), df_pop.head(100), df_country.head(100)], ignore_index=True)

#dfpop, dfrock, dfrap, dfcountry, dfmetal in son 50 satırını al ve tek bir dataframe yap
df250 = pd.concat([df_rap.tail(50), df_metal.tail(50), df_rock.tail(50), df_pop.tail(50), df_country.tail(50)], ignore_index=True)

#describe fonksiyonu ile veri seti hakkında bilgi al
print(df500.describe())
print(df250.describe())

#unique fonksiyonu ile veri setindeki türleri al
print(df500['Genre'].unique())
print(df250['Genre'].unique())



#excel dosyasına kaydet
df500.to_excel('kaggleset500.xlsx', index=False)
df250.to_excel('kaggleset250.xlsx', index=False)
print("Excel dosyaları oluşturuldu.")





