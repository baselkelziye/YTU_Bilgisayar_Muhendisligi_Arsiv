import re, nltk, gensim
import pandas as pd
from IPython.display import display
from sklearn.feature_extraction.text import CountVectorizer
from nltk.stem import WordNetLemmatizer
from nltk.corpus import stopwords

stop_words = set(stopwords.words('english'))
wordnet_lemmatizer = WordNetLemmatizer()
# These should download once.: nltk.download('stopwords')  /  nltk.download('punkt')  /  nltk.download('wordnet')

df = pd.read_csv('../untitled11/Others/datasets/Hotel_Reviews_n40.csv')
print(df.shape)  # knowladge of df

df['State'] = df.Hotel_Address.apply(lambda x: x.split(' ')[-1])  # Adress uzun olduğu için sadece ülke bilgisini aldık.
print(df.Hotel_Name.nunique(), 'hotels belonging to', df.State.unique().size,'different Country in the dataset')
print('Country : ', df.State.unique())
#print('\t\t\t\t\t--------Hotels--------\n', df['Hotel_Name'].unique())

# Aşağıdaki iki satırda otel ismi sorulur ve verilen otele ait bilgilerle işlem yapılır.
#isim = input("Please enter hotel name?")
#df_com = df[(df.Hotel_Name == isim)][['Hotel_Name','Reviewer_Score','Negative_Review','Review_Total_Negative_Word_Counts','Positive_Review','Review_Total_Positive_Word_Counts','Total_Number_of_Reviews','Total_Number_of_Reviews_Reviewer_Has_Given']]
df_com = df[['Hotel_Name','Reviewer_Score','Negative_Review','Review_Total_Negative_Word_Counts','Positive_Review','Review_Total_Positive_Word_Counts','Total_Number_of_Reviews','Total_Number_of_Reviews_Reviewer_Has_Given']]

# NLP prepross NEGATIVE and pos reviews
neg = []
negc = []
for i in df_com['Negative_Review']:    #i:   The hotel was perfect
    letters = re.sub('[^a-zA-Z]', ' ', i)  # sadece harflerden oluşsun noktalamaları/sayıları kaldır. #letters:   The hotel was perfect
    tokens = nltk.word_tokenize(letters)  # herbir kelimeyi ayrı birer string yapar kelimeler listesi yapar #tokens:  ['The', 'hotel', 'was', 'perfect']
    lowercase = [l.lower() for l in tokens] #lowercase:  ['the', 'hotel', 'was', 'perfect']
    filtered_result = list(filter(lambda l: l not in stop_words, lowercase))    #filtered_result:  ['hotel', 'perfect']
    lemmas = [wordnet_lemmatizer.lemmatize(t) for t in filtered_result]  # sondaki çoğul eki kaldırır  #lemmas:  ['hotel', 'perfect']
    neg.append(' '.join(lemmas))  # dizinin sonuna ekle
    negc.append(lemmas)

# NLP prepross positive reviews
pos = []
posc = []
for i in df_com['Positive_Review']:
    pletters = re.sub('[^a-zA-Z]', ' ', i)
    ptokens = nltk.word_tokenize(pletters)
    plowercase = [l.lower() for l in ptokens]
    pfiltered_presult = list(filter(lambda l: l not in stop_words, plowercase))
    plemmas = [wordnet_lemmatizer.lemmatize(t) for t in pfiltered_presult]
    pos.append(' '.join(plemmas))
    posc.append(plemmas)

top = []
top = negc + posc; # Bu diziyi Word2Vec'i oluştururken kullanacağız.

# ---------------------------------------Word2Vect---------------------------------------------------------------

model = gensim.models.Word2Vec(top, size=150, window=10, min_count=2, workers=10)
model.train(top, total_examples=len(top), epochs=10)

def word2vectfonc(kdizi, k):
    print( str(k) +". Most similar to {0}".format(kdizi), model.wv.most_similar(positive=kdizi, topn=5))
    dizi = model.wv.most_similar(positive=kdizi, topn=5)
    for i in dizi:
        kdizi.append(i[0])

dstaff = ['staff']
dloc = ["location"]
droom = ['room']
dbreakfast = ["breakfast"]
dbed = ["bed"]
dservice = ["service"]
dbath = ["bathroom"]
dview = ["view"]
dfood = ["food"]
drest = ["restaurant"]

word2vectfonc(dstaff, 1)
word2vectfonc(dloc, 2)
word2vectfonc(droom, 3)
word2vectfonc(dbreakfast, 4)
word2vectfonc(dbed, 5)
word2vectfonc(dservice, 6)
word2vectfonc(dbath, 7)
word2vectfonc(dview, 8)
word2vectfonc(dfood, 9)
word2vectfonc(drest, 10)

# ---------------------------------------------Count Vectorizer---------------------------------------------------------
# Finding most important words in Negative Reviews
print(' ')
cv = CountVectorizer(analyzer='word', stop_words='english', max_features=100, ngram_range=(3, 3))
# Kelime kelime n gram bunu harf harf te yapabiliriz. Bunu analyses keyi ile belirliyoruz. Ve n-gram buna göre yapılacak
# The lower and upper boundary of the range of n-values for different word n-grams or char n-grams to be extracted.
# All values of n such such that min_n <= n <= max_n will be used. For example an ngram_range of (1, 1) means only unigrams,
# (1, 2) means unigrams and bigrams, and (2, 2) means only bigrams. Only applies if analyzer is not callable.
print(cv)  # hangi özelliklerde bir vectorizer olacak
most_negative_words = cv.fit_transform(neg)
# print(cv.get_feature_names()) #['bed bit hard', 'breakfast included price', 'breakfast room small', 'building work going', 'coffee making facility', ...
# print(most_negative_words) #(35, 15)	1 /(80, 9)	1  / (35, 15)	1
# print(most_negative_words.size)  # 605 tane var
temp_counts = most_negative_words.sum(axis=0)  # axis=0 demek 0 olan yerleri none yapma 0 olarak hesaba kat demek.
# print(temp_counts) #[[15 33 16 14 22 16 14 17 14 86 13 24 17 70 58 23 16 19 24 15 13 13 16 20  17]]
temp_words = cv.vocabulary_  # {'room really small': 15, 'room bit small': 9, 'bed bit hard': 0, 'room size small': 16, 'tea coffee room': 24,
print('the most important words in Negative Reviews: \n--------------------------------------------')
dizii2 = []

def negfonks(dizii):
    x = 0
    for key, value in dict.items(temp_words):
        for i in dizii:
            if i in key and x < 8:
                print(dizii[0], " :", key, "   -", i)
                x = x + 1
                dizii2.append(key)

negfonks(dstaff)
negfonks(dstaff)
negfonks(dloc)
negfonks(droom)
negfonks(dbreakfast)
negfonks(dbed)
negfonks(dservice)
negfonks(dbath)
negfonks(dview)
negfonks(dfood)
negfonks(drest)
display(temp_words)

print('                                          ')
cv = CountVectorizer(analyzer='word', stop_words='english', max_features=100, ngram_range=(2, 2))
most_positive_words = cv.fit_transform(pos)
temp1_counts = most_positive_words.sum(axis=0)
temp1_words = cv.vocabulary_

print('The most important words in Positive Reviews: \n--------------------------------------------')
dizii1 = []

def posfonks(dizii):
    x = 0
    y = 0
    for key, value in dict.items(temp1_words):
        for i in dizii:
            if i in key and x < 8:
                print(dizii[0], " :", key, "   -", i)
                dizii1.append(key)
                x = x + 1

posfonks(dstaff)
posfonks(dloc)
posfonks(droom)
posfonks(dbreakfast)
posfonks(dbed)
posfonks(dservice)
posfonks(dbath)
posfonks(dview)
posfonks(dfood)
posfonks(drest)
display(temp1_words)