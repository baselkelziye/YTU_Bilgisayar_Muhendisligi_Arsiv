import nltk
from nltk.stem import WordNetLemmatizer
# Kelimelerin gövdesini çıkarmak için kullanacağız
lemmatizer = WordNetLemmatizer()
import json
import pickle
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from keras.models import Sequential
from keras.callbacks import EarlyStopping
from keras.layers import Dense, Activation, Dropout
from keras.optimizers import SGD
import random
words=[]
classes = []
documents = []
ignore_words = ['?', '!',',','\'','(',')']
data_file = open('intents.json').read()
intents = json.loads(data_file)
classesCounts = {}
wordsCountPatterns = {}
for intent in intents['intents']:
    if intent['tag'] not in classesCounts:
        classesCounts[intent['tag']] = 1
    else:
        classesCounts[intent['tag']]+=1
    for pattern in intent['patterns']:

        # Cümle içindeki tüm kelimeleri parçalayarak bir diziye ata
        w = nltk.word_tokenize(pattern)
        words.extend(w)
        for countWotd in w:
            if lemmatizer.lemmatize(countWotd.lower()) in wordsCountPatterns:
                wordsCountPatterns[lemmatizer.lemmatize(countWotd.lower())]+=1
            else:
                wordsCountPatterns[lemmatizer.lemmatize(countWotd.lower())]=1
        # İlgili kelimeleri ait olduğu tag ile dökümana ekle.
        documents.append((w, intent['tag']))

        # Tagleri sınıf listeme koy.
        if intent['tag'] not in classes:
            classes.append(intent['tag'])
            
        

# Her kelimeyi ayrı ayrı küçük harfleriyle gövdele ve tekrarı ortadan kaldır.
words = [lemmatizer.lemmatize(w.lower()) for w in words if w not in ignore_words]
# Sırala
words = sorted(list(set(words)))
# Sınıfları Sırala
classes = sorted(list(set(classes)))

# "documents" terimi, "patterns" ve "intents" terimlerinin bir kombinasyonu olarak tanımlanır.
# Döküman uzunluğunu yazdıyor
print (len(documents), "documents")
# Sınıflar intents sayısı kadar, tag sayısı kadar. Uzunluğu yazdırıyoruz.
print (len(classes), "classes", classes)
# Kelimeler de intents.json dosyasında geçen tüm farklı kelime gövdesi sayısı kadar. Bunu yazdırıyoruz.
print (len(words), "unique lemmatized words", words)

# Sınıf ve kelimeleri dosyaya ileride okunmak üzre yaz.
pickle.dump(words,open('words.pkl','wb'))
pickle.dump(classes,open('classes.pkl','wb'))
pickle.dump(wordsCountPatterns,open('wordsCountPatterns.pkl','wb'))
pickle.dump(classesCounts,open('classesCounts','wb'))
# Eğitim verisini oluştur.
training = []
# Çıktımız için boş dizi oluşturduk.
output_empty = [0] * len(classes)
# Her cümle için kelime çantası oluşturma.
for doc in documents:
    # Kelime çantasını ilklendirdik.
    bag = []
    # Parçalanmış cümlenin kelimelerinin listesi.
    pattern_words = doc[0]
    # İlgili dökümanın kelimelerini gövdeleme işlemi.
    pattern_words = [lemmatizer.lemmatize(word.lower()) for word in pattern_words]
    # Dökümanda geçen kelimelerin karşılığının 1, geçmeyenlerin 0 olduğu dizi oluştur.
    for w in words:
        bag.append(1) if w in pattern_words else bag.append(0)
    
    # 0'lardan oluşan diziyi listeye dönüştür.
    output_row = list(output_empty)

    output_row[classes.index(doc[1])] = 1
    # Train verisine işlediğim veriyi ekledim. 
    training.append([bag, output_row])
# Train verisini daha homojen dağıtmak maksadıyla karıştırdım.
random.shuffle(training)
training = np.array(training)
# X-> Patterns   Y-> İntents'den oluşan test ve eğitim listelerini oluşturma.
train_x = list(training[:,0])
train_y = list(training[:,1])
print("Training data created")

# Model oluşturma - 3 katmanlı. İlk katman 128 nörona sahip, ikinci katman 64 nörona sahip ve üçüncü çıktı katmanındaki nöron sayısı intent sayısına eşit.
# LSTM RNN

# Bu kod parçacığı, Keras kütüphanesi kullanılarak bir derin öğrenme modelinin oluşturulmasını gösterir. "Sequential" modeli kullanılarak bir model oluşturulur ve bu modelin üç tane "Dense" adı verilen derin öğrenme katmanı eklenir. Bu katmanlar arasında, "Dropout" adı verilen birer katman da eklenir. 
# "Dense" katmanları, verilerin çapraz geçişli bir şekilde işlenmesini sağlar ve "Dropout" katmanları ise ağın öğrenme sırasında aşırı uyumunu önlemek için kullanılır. 
#"Dense" katmanlarının ilki, giriş verisinin boyutlarını belirten bir "input_shape" parametresi alır ve bu katmana ait bir "activation" parametresi de verilir. Bu parametre, katmanın çıktısının nasıl hesaplanacağını belirler ve "relu" (rectified linear unit) olarak verilir. 
# Son "Dense" katmanı ise, çıktı verisinin boyutlarını belirten bir "len(train_y[0])" parametresi alır ve bu katmana ait "activation" parametresi "softmax" olarak verilir. Bu parametre, katmanın çıktısının sınıflandırma işlemi için kullanılacağını belirtir ve çıktı verisinin olasılık dağılımını hesaplar.
model = Sequential()
model.add(Dense(128, input_shape=(len(train_x[0]),), activation='relu'))
model.add(Dropout(0.5))
model.add(Dense(64, activation='relu'))
model.add(Dropout(0.5))
model.add(Dense(len(train_y[0]), activation='softmax'))

# Modeli compile etme. Ağırlıkları normalize etme.
sgd = SGD(lr=0.01, decay=1e-6, momentum=0.9, nesterov=True)
model.compile(loss='categorical_crossentropy', optimizer=sgd, metrics=['accuracy'])

model.compile(loss = 'categorical_crossentropy',
             optimizer = "adam",
             metrics=["accuracy"])
# Modeli eğitme ve kaydetme
hist = model.fit(np.array(train_x), np.array(train_y), epochs=200, batch_size=5,shuffle=True, verbose=1)
model.save('chatbot_model.h5', hist)

print("model created")