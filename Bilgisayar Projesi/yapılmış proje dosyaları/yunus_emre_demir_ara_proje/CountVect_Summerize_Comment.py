import re, nltk
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
from nltk.stem import WordNetLemmatizer
from nltk.corpus import stopwords
from sklearn.feature_extraction.text import CountVectorizer
stop_words = set(stopwords.words('english'))
wordnet_lemmatizer = WordNetLemmatizer()
#Bunları yüklememi IDE söyledi. 1 kereye mahsus  //  nltk.download('stopwords')   //  nltk.download('punkt')  //  nltk.download('wordnet')

df = pd.read_csv('C:/Users/Demir/PycharmProjects/untitled11/Others/datasets/Hotel_Reviews_n40.csv')

print(df.shape) # Veritabanının (satır,sütun) bilgisi

df['State'] = df.Hotel_Address.apply(lambda x: x.split(' ')[-1])  # Adress uzun ya bundan sadece Ülkeyi almak için yaptık bunu
print(df.Hotel_Name.nunique(), 'hotels belonging to', df.State.unique().size,'different Country in the dataset')
print('Country : ', df.State.unique(),'\n')
print('\t\t\t\t\t--------Hotels--------\n', df['Hotel_Name'].unique())


isim = input("Please enter hotel name?")
df_com = df[(df.Hotel_Name == isim)][['Hotel_Name','Reviewer_Score','Negative_Review','Review_Total_Negative_Word_Counts','Positive_Review','Review_Total_Positive_Word_Counts','Total_Number_of_Reviews','Total_Number_of_Reviews_Reviewer_Has_Given']]
df_com = df[(df.Hotel_Name == 'H tel Original Paris')][['Hotel_Name','Reviewer_Score','Negative_Review','Review_Total_Negative_Word_Counts','Positive_Review','Review_Total_Positive_Word_Counts','Total_Number_of_Reviews','Total_Number_of_Reviews_Reviewer_Has_Given']]
# df_com = df[['Hotel_Name','Reviewer_Score','Negative_Review','Review_Total_Negative_Word_Counts','Positive_Review','Review_Total_Positive_Word_Counts','Total_Number_of_Reviews','Total_Number_of_Reviews_Reviewer_Has_Given']]

# NLP prepross NEGATIVE and pos reviews
neg = []
for i in df_com['Negative_Review']:
    #print('i: ', i)  #i:   The hotel was perfect
    letters = re.sub('[^a-zA-Z]', ' ', i)  #sadece harflerden oluşsun noktalamaları/sayıları kaldır.
    #print('\nletters: ', letters) #letters:   The hotel was perfect
    tokens = nltk.word_tokenize(letters)  # herbir kelimeyi ayrı birer string yapar kelimeler listesi yapar
    #print('\ntokens: ', tokens) #tokens:  ['The', 'hotel', 'was', 'perfect']
    lowercase = [l.lower() for l in tokens]
    #print('\nlowercase: ', lowercase) #lowercase:  ['the', 'hotel', 'was', 'perfect']
    filtered_result = list(filter(lambda l: l not in stop_words, lowercase))
    #print('\nfiltered_result: ', filtered_result) #filtered_result:  ['hotel', 'perfect']
    lemmas = [wordnet_lemmatizer.lemmatize(t) for t in filtered_result]   #hiçbişi yapmıyor :) sondaki çoğul eki kaldırması beklenir ama gidip us un s sini kaldırır :)
    #print('\nlemmas: ', lemmas) #lemmas:  ['hotel', 'perfect']
    neg.append(' '.join(lemmas))  #dizinin sonuna ekle
    #print('\n',neg) # ['hotel perfect']

print('\n',neg) # ['hotel perfect']

#NLP prepross positive reviews
pos = []
for i in df_com['Positive_Review']:
    pletters = re.sub('[^a-zA-Z]', ' ', i)
    ptokens = nltk.word_tokenize(pletters)
    plowercase = [l.lower() for l in ptokens]
    filtered_presult = list(filter(lambda l: l not in stop_words, plowercase))
    plemmas = [wordnet_lemmatizer.lemmatize(t) for t in filtered_presult]
    pos.append(' '.join(plemmas))

# Finding most important words in Negative Reviews
print(' ')
cv = CountVectorizer(analyzer='word', stop_words='english', max_features=25, ngram_range=(3,3))
    # Kelime kelime n gram bunu harf harf te yapabiliriz. BUnu analyses keyi ile belirliyoruz. Ve n-gram buna göre yapılacak
    #The lower and upper boundary of the range of n-values for different word n-grams or char n-grams to be extracted.
    #All values of n such such that min_n <= n <= max_n will be used. For example an ngram_range of (1, 1) means only unigrams,
    #(1, 2) means unigrams and bigrams, and (2, 2) means only bigrams. Only applies if analyzer is not callable.
print(cv)
most_negative_words = cv.fit_transform(neg)
print(cv.get_feature_names()) #
print(most_negative_words)
print(most_negative_words.size)
temp_counts = most_negative_words.sum(axis=0) # axis=0 demek 0 olan yerleri none yapma 0 olarak hesaba kat demek.
print(temp_counts)
temp_words = cv.vocabulary_
print('the most important words in Negative Reviews: \n--------------------------------------------')
for x in temp_words:
    print(x)
#display(temp_words)


print('                                          ')
cv = CountVectorizer(analyzer='word', stop_words='english', max_features=25, ngram_range=(2, 2))
most_positive_words = cv.fit_transform(pos)
temp1_counts = most_positive_words.sum(axis=0)
temp1_words = cv.vocabulary_
print('The most important words in Positive Reviews: \n--------------------------------------------')
for aaa in temp1_words:
    print(aaa)
#display(temp1_words)




df_com['+'] = 1
df_com['-'] = 1
df_com['+'] = df_com.apply(lambda x: 0 if x["Positive_Review"] == 'No Positive' else x['+'],axis =1)
df_com['-'] = df_com.apply(lambda x: 0 if x["Negative_Review"] == 'No Negative' else x['-'],axis =1)
counted_reviews = pd.DataFrame(df_com.groupby(['Hotel_Name'])[['+','-','Total_Number_of_Reviews_Reviewer_Has_Given']].sum())
counted_reviews['Total'] = counted_reviews['+'] +counted_reviews['-']
counted_reviews['Neg_rate'] = round(counted_reviews['-'] / counted_reviews['Total'],2)
counted_reviews['Neg_rate'].describe()

print(counted_reviews)