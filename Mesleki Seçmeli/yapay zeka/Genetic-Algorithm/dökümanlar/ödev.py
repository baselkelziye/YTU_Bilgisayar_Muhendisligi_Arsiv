from types import FunctionType
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem.porter import PorterStemmer
import json
import random
from enum import Enum
import matplotlib.pyplot as plt
import string


# Okunaklılığın artması için
class Intent(Enum):
    POSITIVE = 0
    NEGATIVE = 1




# Pozitif kelimeler ve sayıları saklanıyor
positiveWords = []
positiveWordsCounts = {}

# Negatif kelimeler ve sayıları saklanıyor
negativeWords = []
negativeWordsCounts = {}

# En yüksek doğruluk oranına sahip bireyin oranı
overAllMax = 0
max = 0
bestIndividual = [[],[]]
overAllGenerationCount = 0

# Ortalama doğruluk oranı
acc = 0

# En yüksek doğruluk oranına sahip bireyin indeksi
maxIndex = 0

# % olarak mutasyon olasılığı
mutationRate = 3

# Belirlenen başarı oranı
breakRate = 1

# Belirlenen başarı oranı sağlanmazsa, maksimum sonlandırma değeri
tryCount = 10


# Birey dizisi
individuals = []

# Birey dizisiin büyüklüğü
individualSize = 8

# Bireylerin çantasındaki kelimelerin büyüklüğü (individualWordSize = 5 ise, 5 kelime olumlu 5 kelime olumsuz)
individualWordSize = 10

# Olumlu json verileri
positive_json_data = {}

# Olumsuz json verileri
negative_json_data = {}


# Birey oluşturma işlemleri
def individualGenerate():
    global individualWordSize
    # Bireyi ilklendirme
    indivisual = [[],[]]

    # İstenilen birey sayısı kadar birey oluşturma
    for i in range(0,individualWordSize):

        # Pozitif ve negatif kelime eklemek için iki tane rastgele indis oluşturma
        random_number_positive = random.randint(0, len(positiveWords) - 1)
        random_number_negative = random.randint(0, len(negativeWords) - 1)

        # Oluşturulan kelime bireyde zaten mevcutsa tekrardan rastgele indis ataması yaptım
        while (positiveWords[random_number_positive] in  indivisual[Intent.POSITIVE.value]):
            random_number_positive = random.randint(0, len(positiveWords) - 1)

        # Oluşturulan kelime bireyde zaten mevcutsa tekrardan rastgele indis ataması yaptım
        while (negativeWords[random_number_negative] in  indivisual[Intent.NEGATIVE.value]):
            random_number_negative = random.randint(0, len(negativeWords) - 1)

        # Kelimeleri ekleme işlemleri
        indivisual[Intent.POSITIVE.value].append(positiveWords[random_number_positive])
        indivisual[Intent.NEGATIVE.value].append(negativeWords[random_number_negative])
    return indivisual


#Json verilerini okuma ve döndürme işlemi
def initializeJson():
    global positive_json_data, negative_json_data
    with open('philosphy_intents.json') as f:
        positive_json_data = json.load(f)

    with open('nonphilosphy_intents.json') as f:
        negative_json_data = json.load(f)


# Cümleyi ön işlemden geçirme, noktalama işaretleri, bağlaç vb.'den arındırma ve harfleri küçültme. Sonrasında ayrı ayrı dizi halinde döndürme " "'dan ayırarak.
def preproccessText(intentText):
    filtered_words = []
    tmpText = intentText.lower()
    text_without_punctuations = "".join([char for char in tmpText if char not in string.punctuation])
    tmpWords = text_without_punctuations.split()
    filtered_words +=[tmpWord for tmpWord in tmpWords if tmpWord not in stopwords.words('english')]
    return filtered_words


# Birey için cümle eğer pozitifse true, negatifse false döndürüyor. Bir cümlenin pozitif sayılması için pozitif olarak tahmin ettiği kelime sayısının fazla olması gerekiyor
def calculatePositive(individual,intentText):
    # Pozitif tahmin edilen kelime sayısı
    positive = 0

    # Negatif tahmin edilen kelime sayısı
    negative = 0

    # Verilen cümleyi ön işlemden geçirme
    tmpWords = preproccessText(intentText)


    # Kelimeleri köklerine ayırmak için kullanacağız
    stemmer = PorterStemmer()
    stemmed_words = []

    # Ön işlemden geçmiş tüm kelimeleri köklerine ayırma ve yeni diziye ekleme işlemi
    for word in tmpWords:
        stemmed_words.append(stemmer.stem(word))

    # Olumlu kelimelerin geçme sayısını bulma işlemi
    for word in individual[Intent.POSITIVE.value]:
        if word in stemmed_words:
            positive+=1

    # Olumsuz kelimelerin geçme sayısını bulma işlemi
    for word in individual[Intent.NEGATIVE.value]:
        if word in stemmed_words:
            negative+=1 

    # Sonucu boolean olarak döndürmek
    return positive>negative


# Json verilerinin tamamını ön işlemden geçirme
def preprocess(json_data):
    # Ön işlemden geçmiş tüm kelimeleri tutan dizi
    filtered_words = []

    # Verilen json içindeki tüm cümleleri gezerek, ön işlem uygulayıp, elde edilen sonucu diziye ekleme
    for intent in json_data['intents']:
        filtered_words +=preproccessText(intent['text'])

    # Kelimeleri köklerine ayırmak için kullanacağız
    stemmer = PorterStemmer()
    stemmed_words = []

    # Ön işlemden geçmiş tüm kelimeleri köklerine ayırma ve yeni diziye ekleme işlemi
    for word in filtered_words:
        stemmed_words.append(stemmer.stem(word))

    words = []
    word_counts = {}
    # Benzersiz kelimelerden oluşan bir sözlük oluşturma işlemi
    for word in stemmed_words:
        if word not in words:
            words.append(word)
            word_counts[word] = 1
        else:
            word_counts[word] += 1
    return words, word_counts
    




# Bireyin başarım oranını hesaplama
def calculateResultForOneIndividual(individual):
    # Doğru bilinen cümle sayısı
    trueCounter = 0
    # Yanlış bilinen cümle sayısı
    falseCounter = 0

    # Olumlu cümlelere göre doğru-yanlış hesaplama
    for intent in positive_json_data['intents']:
        if(calculatePositive(individual, intent['text'])):
            trueCounter+=1
        else:
            falseCounter+=1

    # Olumsuz cümlelere göre doğru-yanlış hesaplama
    for intent in negative_json_data['intents']:
        if(calculatePositive(individual,intent['text'])):
            falseCounter+=1
        else:
            trueCounter+=1
    #Oran döndürme
    return trueCounter / (trueCounter+falseCounter)

# Sonuçları yazdırma işlemi
def printResults():
    global max, maxIndex, acc
    print("Overall accuracy rate is " + str(acc))
    print("Best accuracy rate is " + str(max))
    print(individuals[maxIndex])


# Verilen indis değerine göre (0-Pozitif), (1-Negatif) kelime çantasını sıralar
def sortIndividualPart(individual, index):

    # Eğer Negatif sözlükte işlem yapılmak isteniyosa negatifle, yoksa pozitifle işlem yapılacak
    if index == Intent.NEGATIVE.value:
        wordsCount = negativeWordsCounts
    else:
        wordsCount = positiveWordsCounts

    sorted = []
    sorted.append(individual[index][0])

    # Buradaysa geçme sıklığına büyükten küçüğe sıralama işlemi yapılıyor, amacı en çok geçen kelimeleri çantaya katmak
    for i in range(1,len(individual[index])):
        j = len(sorted)-1
        if wordsCount[individual[index][i]]>wordsCount[sorted[j]]:
            flag = True
            while(j > -1 and flag):
                if wordsCount[individual[index][i]]<wordsCount[sorted[j]]:
                    flag = False
                else:
                    j-=1
            if(not flag):
                sorted.insert(j-1, individual[index][i])
            elif(j>-1):
                sorted.insert(j, individual[index][i])
            else:
                sorted.insert(0, individual[index][i])

        else:
            sorted.append(individual[index][i])
    return sorted


# Bireyin kelimelerini geçme sıklığına göre sıralama işlemi
def sortIndividual(individual):
    individual[Intent.NEGATIVE.value] = sortIndividualPart(individual,Intent.NEGATIVE.value)
    individual[Intent.POSITIVE.value] = sortIndividualPart(individual,Intent.POSITIVE.value)   
    return individual


# Verilen eski bireyin çantasındaki kelimeleri, bölme saısına kadar yeni bireye ekleme işlemi
def appendIndividualFromDivide(oldIndividual, newIndividual, randDivide):
    for i in range(0,randDivide):  
        # Her kelime için mutasyon sayısı belirleme
        randMutation = random.randint(0, 100)
        
        # Mutasyon oranı yakalandıysa mutasyon gerçekleştirme, eğer çantada bulunan bir kelime geldiyse yine mutasyon gerçekleştirme yoksa doğrudan kelimeleri ekleme işlemi
        if(randMutation > mutationRate and oldIndividual[Intent.POSITIVE.value][i] not in newIndividual[Intent.POSITIVE.value]
            and oldIndividual[Intent.NEGATIVE.value][i] not in  newIndividual[Intent.NEGATIVE.value]):
            newIndividual[Intent.POSITIVE.value].append(oldIndividual[Intent.POSITIVE.value][i])
            newIndividual[Intent.NEGATIVE.value].append(oldIndividual[Intent.NEGATIVE.value][i])
        else:
            newIndividual[Intent.POSITIVE.value].append(positiveWords[i])
            newIndividual[Intent.NEGATIVE.value].append(negativeWords[i])

    return newIndividual

# Crossover işlemleri
def reGenerateIndividuals(individual1,individual2):
    # Hangi kelimeden itibaren bölme işlemi gerçekleşecek
    randDivide = random.randint(0, individualWordSize - 1)

    # Kelimele çantalarını kelimelerin sıklıklarına göre sıralama işlemi
    individual1 = sortIndividual(individual1)
    individual2 = sortIndividual(individual2)

    # Yeni bireyi ilklendirme
    individual = [[],[]]
    # İlk bireyin karılmış çantasındaki kelimelerin rastgele bölme sayısına kadar yeni oluşacak bireye eklenmesi
    individual = appendIndividualFromDivide(individual1, individual, randDivide)

    # İkinci bireyin karılmış çantasındaki kelimelerin rastgele bölme sayısından geriye kalan eleman sayısı kadar
    # (örneğin 10 kelime var rastgele bölme sayısı 3, geriye 7 eleman kalır) yeni oluşacak bireye eklenmesi
    individual = appendIndividualFromDivide(individual2, individual, individualWordSize-randDivide)

    
    return individual


# Bireyleri ilklendirme işlemleri
def initIndividuals():
    global acc, max, maxIndex
    acc = 0
    max = 0
    tmpMax = 0


    # İstenen birey sayısı kadar birey oluşturma
    for i in range(0,individualSize):
        individuals.append(individualGenerate())

    
    # Her birey için olasılık hesaplama ve ilgili acc, max ve maxIndex değerlerini güncelleme
    for i in range(0,individualSize):
        tmpMax = calculateResultForOneIndividual(individuals[i])
        acc += tmpMax
        if tmpMax>max:
            max = tmpMax
            maxIndex = i
    acc/= individualSize




# En yüksek başarıma sahip bireyin başarım oranını bulmak
def calculateMaxCorrect():
    global max, maxIndex
    max = 0
    tmpMax = 0
    for i in range(0,individualSize):
        tmpMax = calculateResultForOneIndividual(individuals[i])
        if tmpMax>max:
            max = tmpMax
            maxIndex = i

# Aynı bireyin kopyasını üretir
def individualCopy(oldIndividual):

    newIndividual = [[],[]]

    for i in oldIndividual[Intent.POSITIVE.value]:
        newIndividual[Intent.POSITIVE.value].append(i)

    for i in oldIndividual[Intent.NEGATIVE.value]:
        newIndividual[Intent.NEGATIVE.value].append(i)

    return newIndividual

# Birey sayısı kadar yeni nesil oluşturma işlemi Crossover
def reGenerateAllIndividuals(individuals):
    global max, maxIndex, acc
    # Her bireyin başarım oranının tutulması
    achievement = []

    # Toplam orana göre, örneğin 0.5, 0.3, 0.7  = 1.5 -> 1.5*100 = 150, rastgele sayı belirleme aralığı
    total = 0

    # İlk eski bireyi ilklendirme
    individual1 = [[],[]]

    # İkinci eski bireyi ilklendirme
    individual2 = [[],[]]

    # Ortalama başarım hesabı için başarımın sıfırlanması
    acc = 0

    # Yeni oluşan nesli tutacak dizi
    tmpIndividuals = []

    # En fazla başarımı sağlayan elemanın başarım oranların durunması
    calculateMaxCorrect()

    # Ortalama başarım oranının her birey için hesaplanması ve oran aralıklarının diziye eklenmesi 
    # Örneği 4 tane birey olsun bunların başarımları da 0.1, 0.2, 0.3, 0.4 olsun
    # Dizinin elemanları sırasıyla 0, 10, 30, 70 olacaktır ürettiğimiz rastgele sayıdan büyük olan
    # En küçük sayıya kadar iterasyon dönülecek ve o indise sahip birey crossover için kullanılacaktır
    for i in range(0,individualSize):
        achievement.append(acc*100)
        tmpMax = calculateResultForOneIndividual(individuals[i])
        acc += tmpMax
    
    # Başarım oranlarına göre rastgele seçilecek sayı oluşturmak için değişken ataması
    total = int(100 * acc)

    # Ortalama başarımı hesaplama
    acc/= individualSize

    # Burada birey sayısı kadar yeni birey üretme işlemi
    for i in range(0, individualSize):

        # Başarım oranına bağlı rastgele seçim için sayılar üretme
        randSelect1  = random.randint(0, total)
        randSelect2  = random.randint(0, total)

        indiviudalOneIndex = 0

        # Crossoverda kullanılacak ilk bireyi seçme
        for j in range(0,individualSize):
            if randSelect1 > achievement[j]:
                individual1 = individualCopy(individuals[j])
                indiviudalOneIndex = j
                break
        
        # Crossoverda kullanılacak ikinci bireyi seçme
        for j in range(0,individualSize):
            if randSelect2 > achievement[j]:
                # Rastgele seçilen bireyler aynıysa yeni seçim yapma işlemi
                if(individuals[j]!=individual1):
                    individual2 = individualCopy(individuals[j])
                    break
                elif(indiviudalOneIndex>1):
                    individual2 = individualCopy(individuals[j-1])
                else:
                    individual2 = individualCopy(individuals[j+1])
                    
        # Seçilen iki bireyle yenibirey oluşturup, yeni nesli tutan diziye ekleme işlemi
        tmpIndividuals.append(reGenerateIndividuals(individual1, individual2))

    return tmpIndividuals

        
def individualToStr(individual):
    tempstr = "---Positive---"
    for i in individual[Intent.POSITIVE.value]:
        tempstr+=" - " + i
    
    tempstr +=" ---Negative--- "
    for i in individual[Intent.NEGATIVE.value]:
        tempstr+=" - " + i
    return tempstr

# Json verilerinin okunması
initializeJson()

# Kelimeleri temizleme işlemleri
positiveWords, positiveWordsCounts = preprocess(positive_json_data)
negativeWords, negativeWordsCounts = preprocess(negative_json_data)

# Bireyleri oluşturma ve doğruluk oranlarını hesaplama işlemleri 
initIndividuals()



# Sonuç yazdırma
printResults()

overAllMax = max
bestIndividual = individuals[maxIndex]

# Çizdirme işlemi için ve işlem sayısını için tutmak için kullanılan değişken
counter = 0

# Her anki en iyi bireyin durumunu çizdirmek için tutan dizi
best_performance_scores = []

# Her anki bireylerin ortalama durumunu çizdirmek için tutan dizi
performance_scores = []

# Adım sayısını çizdirmek için tutan dizi
iteration_numbers = []

generationCount = 1

while(max < breakRate and counter <tryCount):
    # Crossover ve mutasyonla ilk neslin yok edilip bir sonraki neslin oluşturulması
    individuals = reGenerateAllIndividuals(individuals)

    # Sonuçları yazdırma
    printResults()

    # Anlık ortalama başarım sonucunu çizdirmek için diziye ekleme
    performance_scores.append(acc*100)

    # En iyi başarıma sahip bireyin başarım sonucunu çizdirmek için diziye ekleme
    best_performance_scores.append(max*100)

    # İşlem sayısını artırıp, işlem sayısını tutan diziye ekleme
    counter+=1
    iteration_numbers.append(counter)

    # Overall güncelleme
    if overAllMax < max:
        overAllMax = max
        bestIndividual = individuals[maxIndex]
        overAllGenerationCount = generationCount

    generationCount+=1
    

fig, axs = plt.subplots(1, 2, figsize=(10,5))

axs[0].plot(iteration_numbers, performance_scores, linestyle='--', marker='o', color='b')
axs[0].set_title("Average")
axs[0].set_xlim(1, len(iteration_numbers)+1)
axs[0].set_ylim(0, (overAllMax+0.1)*100)
axs[0].grid(True)

axs[1].plot(iteration_numbers, best_performance_scores, linestyle='--', marker='o', color='g')
axs[1].set_title("Best")
axs[1].set_xlim(1, len(iteration_numbers)+1)
axs[1].set_ylim(0, (overAllMax+0.1)*100)
axs[1].grid(True)



# Kaydetmek için
figureName = "Mutation " + str(mutationRate) + "Size " + str(individualSize) +"Word Size"  + str(individualWordSize)
plt.savefig(figureName)
print(figureName + " İsimli Figür Kaydedildi")

dataName = "Overall Max "+ str(overAllMax) + "Generation count "+ str(overAllGenerationCount)

with open(dataName + ".json", "w") as f:
    
    json.dump(individualToStr(bestIndividual), f)
    print(dataName + " İsimli Dosya Kaydedildi")


plt.show()
