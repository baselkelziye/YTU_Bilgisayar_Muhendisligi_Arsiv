#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Apr 21 00:07:14 2018

@author: egehangunduz
"""
import os
import numpy as np

from skimage import io
from skimage.transform import resize
from skimage import feature
from skimage.color import rgb2gray
from skimage.color import rgb2hsv
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelBinarizer
from sklearn.preprocessing import StandardScaler
from sklearn import metrics
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Conv2D
from keras.layers import Dropout
from keras.layers import Activation
from keras.layers import MaxPooling2D
from keras.layers import Flatten
from keras.layers import PReLU
import timeit



def readImage(image_path):
    image = io.imread(image_path)
    image = resize(image, (256, 256), mode="constant") #tüm resimleri aynı boyuta getir
    return image


def extractFeatures(image_path):
    inputs = []
    image = readImage(image_path) #resmi oku
    
    #canny edge detection ile sigma=3 degerleri ile daha kalın olan kenarları ayır
    #resimdeki kenar miktarının tüm pixellere oranını hesapla
    gray_image = rgb2gray(image) 
    edge = feature.canny(gray_image, sigma=3) 
    inputs = np.append(inputs, (np.count_nonzero(edge) / edge.size))     
    
    #hue mean. resimdeki renk dağılımın oranının ortalamasını alınır
    #hue standard deviation . ortalamayı daha anlamlı yapmak icin resimdeki renk dağılımın oranının standart sapmasını alınır
    hsv = rgb2hsv(image)
    inputs = np.append(inputs, np.mean(hsv[:, :, 0])) 
    inputs = np.append(inputs, np.std(hsv[:, :, 0])) 
    

    #saturation mean. resimdeki renklerinin canlılık ortalamasını al. dusuk degerler resmin daha gri tonlarına kaydığını gösterir
    #saturation standard deviation . ortalamayı anlamlandırmak icin renk canlılık standard sapmasını al
    inputs = np.append(inputs, np.mean(hsv[:, :, 1])) 
    inputs = np.append(inputs, np.std(hsv[:, :, 1])) 
    
    #bias degeri
    inputs = np.append(inputs, 1) #bias
    return inputs


def extractImagePathsAndLabels(path):
    directory_list = [f for f in os.listdir(path) if os.path.isdir(os.path.join(path, f))]   # sadece directoryleri sec
    imagePaths = []
    label = []
    #her bir art klasoru icindeki resimleri al ve hepsini labelları ile beraber path'e eklelenir
    for directory in directory_list:
        image_list = os.listdir(os.path.join(path, directory))
        for image in image_list:
            imagePaths = np.append(imagePaths, path + os.sep + directory + os.sep + image)
            label = np.append(label, directory)
    return imagePaths, label




current_directory = os.getcwd() #get current directory
train_path = os.path.join(current_directory, "artpictures", "train") #train image paths
test_path = os.path.join(current_directory, "artpictures", "test") #test image paths

train_image_paths, train_label = extractImagePathsAndLabels(train_path) #egitim resimlerinin path'ini ve etiketlerini al
test_image_paths, test_label = extractImagePathsAndLabels(test_path)  #test resimlerinin path'ini ve etiketlerini al

#train setini karıştırmak icin kullanılır.
#egitim verisi az oldugu icin sıralı egitimde en son "sınıfına" göre ağırlık güncellemesi yapılmasını önlemek için yapılmıştır.
index = np.random.permutation(train_image_paths.shape[0])
train_image_paths,train_label = train_image_paths[index], train_label[index]

label_binarizer = LabelBinarizer()
train_output = label_binarizer.fit_transform(train_label)  #binarize the train labels

trainData = []
testData = []
print ("Reading train images...")
for path in train_image_paths:
    trainData = np.append(trainData, extractFeatures(path))
print ("Reading test images...")
for path in test_image_paths:
    testData = np.append(testData, extractFeatures(path))

#ozellik vektorlerini sinir ağının girişi için uygun matris düzenine getirilir.
trainData = np.reshape(trainData,(train_image_paths.shape[0], int(trainData.shape[0] / train_image_paths.shape[0])))
testData = np.reshape(testData,(test_image_paths.shape[0], int(testData.shape[0] / test_image_paths.shape[0])))

#girişlerin değerlerinin arasındaki farklılıkların giderilmesi için verilere scale işlemi uygulanmıştır.
scaler = StandardScaler()
trainData = scaler.fit_transform(trainData)
testData = scaler.fit_transform(testData)

#layerlar için başlangıç değerleri rastgele atanır. Giriş layeri 
#input katmanına bias eklenir
layer1_w=np.random.rand(trainData.shape[1],7) 
layer2_w=np.random.rand(7,6) 
layer3_w=np.random.rand(6,5)
layer4_w=np.random.rand(5,4) 

sig = lambda t: 1/(1+np.exp(-t))    #sigmoid fonksiyonu
error = [] #her epoch için hata değerinin tutulacağı lise
epoch_index = [] #epoch indexinin tutulacağı değer
number_of_epoch=5000 #toplam epoch sayısı

#öğrenme deperi çeşitli denemeler sonrası 0.03 olarak seçilmiştir.
eta=0.03

# =============================================================================
# EL İLE TASARLANAN AĞ
# Epoch değeri 50 gibi küçük değerler için her denemede tüm çıkışları tek bir sınıf olduğu için epoch değeri yüksek seçilmiştir.
# Sistemin daha hızlı çalışması için her örnek tek tek eğitime alınmak yerine "Vectorized Implementation" yapılıp  matris çarpımları
# kullanılarak sistemin daha hızlı çalışması sağlanmıştır.
# Küçük epoch değerleri için layer sayısının ve örnek sayısının az olmasından ötürü overfitting problemi gözlenmiştir.
# Ödev klasöründe verilen ağ yapısı 7-6-5 idir. 
# Input olarak her resim için 5 özellik alınmış olup bias eklenmiştir. Çıkış sayısı 4tür.
# =============================================================================
print ("El ile tasarlanan ağ için epoch sayısı:" , number_of_epoch)
for i in range(0,number_of_epoch):
    E=0
    layer1=sig(np.dot(trainData,layer1_w))
    layer2=sig(np.dot(layer1,layer2_w))
    layer3=sig(np.dot(layer2,layer3_w))
    layer4=sig(np.dot(layer3,layer4_w))
    
    #hata miktarı her turun sonunda hesaplanır ve error listesine eklenir
    E = 0.5 * ((train_output-layer4)**2)
    
    layer4delta=(layer4-train_output)*layer4*(1-layer4)
    layer3delta=((np.dot(layer4delta,layer4_w.T)))*layer3*(1-layer3)
    layer2delta=((np.dot(layer3delta,layer3_w.T)))*layer2*(1-layer2)
    layer1delta=((np.dot(layer2delta,layer2_w.T)))*layer1*(1-layer1)
    
    #öğrenme oranına göre her epoch sonucu ağırlık güncellemesi yapılır
    layer4_w = layer4_w - (np.dot(layer3.T,layer4delta))*eta
    layer3_w = layer3_w - (np.dot(layer2.T,layer3delta))*eta
    layer2_w = layer2_w - (np.dot(layer1.T,layer2delta))*eta
    layer1_w = layer1_w - (np.dot(trainData.T,layer1delta))*eta
    
    error.append(E.sum()) #her epoch sonunda hata miktarı eklenir
    epoch_index.append(i) #epoch indisi eklenir


# =============================================================================
# Test işlemleri için eğitimde yapıldığı gibi vectorized implementation yapılmıştır.
# =============================================================================
layer1Test=sig(np.dot(testData,layer1_w))
layer2Test=sig(np.dot(layer1Test,layer2_w))
layer3Test=sig(np.dot(layer2Test,layer3_w))
layer4Test=sig(np.dot(layer3Test, layer4_w))
pred = label_binarizer.inverse_transform(layer4Test) #tahmin sonuçlarını al

print ("Test Accuracy:%%%.2f" % (metrics.accuracy_score(test_label,pred)*100))
print ('El ile tasarlanan ağ için hata Grafigi : ')
plt.plot(epoch_index, error)
plt.xlabel("Epoch Value")
plt.ylabel("Error")
plt.title("Hata Grafiği")
plt.show()
print ("-----------------------------\n-----------------------------\n-----------------------------\n")



# =============================================================================
# KERAS 
# input için trainData'sının colon sayısı alınıp hidden layer olarak 7 6 5 değerleri verilmiştir
# Epoch sayısı 5'ten başlayarak 50'ye kadar artırılmış her turda sonuçlar kaydedilip ekrana yazdırılmıştır.
# En yüksek başarıya sahip epcoh seçilip aynı değer ile batch_size 1-2-3-4 için sistem bir daha çalıştırılmıştır.
# Tüm aktivasyon fonksiyonları sigmoid seçilmiş olup çoklu sınıflandırma olduğu için softmax fonksiyonu son layere eklenmiştir.
# =============================================================================

#ara katmanlarda bias kullanılmamıştır.
model = Sequential()
model.add(Dense(7,input_dim=trainData.shape[1],activation= "sigmoid"))
model.add(Dense(6, activation= "sigmoid"))
model.add(Dense(5, activation= "sigmoid"))
model.add(Dense(4, activation= "softmax"))    
#model.summary()
model.compile(optimizer = 'adam', loss = 'categorical_crossentropy', metrics = ['accuracy'])

accuracy = 0
accuracy_list=[] #accuracy degerlerinin tutulacagi list
epoch_list=[] #epoch degerlerinin tutulacagi list

for epoch in range(5,55,5):
    print(epoch , " Epoch için aynı ağ Keras ile eğitiliyor...")
    model.fit(trainData, train_output, epochs=epoch, batch_size = 1, verbose=0) 
    predictions = model.predict(testData, batch_size=1, verbose =0)
    predictions = label_binarizer.inverse_transform(predictions)   
    acc = metrics.accuracy_score(test_label,predictions)
    print ("Test accuracy for ", epoch , "epoch: %%%.2f" % (acc*100) )
    accuracy_list.append(acc)
    epoch_list.append(epoch)
    print ("-----------------------------\n-----------------------------\n")
    #en yuksek accuracy'e sahip olan epoch degerini bulur ve daha sonradan batch_size denemesinde kullanılır
    if (metrics.accuracy_score(test_label,predictions)) > accuracy:
        accuracy = metrics.accuracy_score(test_label,predictions)
        epoch_value = epoch
        
plt.plot(epoch_list,accuracy_list,color="b",marker="^")
plt.xlabel("Epoch Value")
plt.ylabel("Test Accuracy")
plt.title("Epoch Başarı Grafiği")
plt.show()


         
batch_list=[] #bath_size degerlerinin tutulacagi list
accuracy_list2=[] #accuracy degerlerinin tutulacagi list
for batch_number in range(1,5):
    print("En fazla başarıya sahip olan epoch değeri",epoch_value,"ve batch_size",batch_number ,"için aynı ağ Keras ile eğitiliyor...")
    model.fit(trainData, train_output, epochs=epoch_value, batch_size = batch_number, verbose=0)
    predictions = model.predict(testData, batch_size=1, verbose =0)
    predictions = label_binarizer.inverse_transform(predictions)
    acc = metrics.accuracy_score(test_label,predictions)
    print ("Test accuracy for",epoch_value , "epoch and",batch_number,"batch_size: %%%.2f" % (acc*100) )
    batch_list.append(batch_number)
    accuracy_list2.append(acc)
    print ("-----------------------------\n-----------------------------\n")
    
plt.plot(batch_list,accuracy_list2,color="b",marker="^")
plt.xlabel("Batch Size Value")
plt.ylabel("Test Accuracy")
plt.title("Batch_size Başarı Grafiği")
plt.show()
    

# =============================================================================
# CONVOLUTIONAL NEURAL NETWORKS
# Sistem için önce 256x256 resimler okunmuştur.
# Belirtilen 3 aktivasyon ve 1 advance aktivasyon fonksiyonu tanımlanmıştır.
# Çeşitli denemeler sonucu en optimum bulunan sonuçlara gröe CNN tasarlanmıştır.
# Tasarlanan ağda her çalışma sonucu farklı sonuçlar çıkmaktadır. Bu sistemdeki eğitim verisinin az olmasından kaynaklanmaktadır.
# Dense layer'lara aktivasyon eklenmemiştir. 
# Denemeler sonucu overfitting'i önlemek için en ideal Dropout oranı  0.4 seçilip Fully-Connected Layer'dan önce eklenmiştir.
# =============================================================================
trainImages=[]
testImages=[]
#CNN için image'leri oku. Tum resimler 256x256 olarak tekrar boyutlandırılıp okunmuştur.
for path in train_image_paths:
    image=readImage(path) 
    trainImages.append(image)
    
for path in test_image_paths:
    image=readImage(path)
    testImages.append(image)
    
trainImages = np.array(trainImages)
testImages = np.array(testImages)

#Çalıstırılaması istenen aktivasyon fonksiyonları sadece Convolution layerlara uygulanmıştır
activations=["sigmoid","relu","tanh"] #3 aktivasyon fonksiyonu
prelu= PReLU(shared_axes=[1,2])  #advance aktivasyon fonksiyonu
activations.append(prelu)
names=["sigmoid","relu","tanh","prelu"]

for activate,name in zip(activations,names):
    print("CNN, aktivasyon fonksiyonu " , name , " için çalışıyor...")
    classifier = Sequential()
    classifier.add(Conv2D(32, (3,3), input_shape = (256, 256, 3),strides=(2,2),padding="same"))#stride'dan dan dolayı boyut 128x128'e düşer
    classifier.add(Activation(activate))
    classifier.add(MaxPooling2D(pool_size = (4,4))) #boyut 32x32'ye düşer
    classifier.add(Conv2D(32, (3,3),strides=(2,2),padding="same")) #stride'dan dan dolayı boyut 16x16'ya düşer
    classifier.add(Activation(activate))
    classifier.add(MaxPooling2D(pool_size = (4,4))) #boyut 4x4'e düşer
    
    classifier.add(Flatten()) #4x4x32 lik matris vektör haline getirilir.(32 burada kernel sayımızdır)
    classifier.add(Dense(512)) 
    classifier.add(Dense(128))
    classifier.add(Dense(32)) 
    classifier.add(Dropout(0.4)) #Overfitting'i önlemek için denemeler sonucu 0.4 Dropout layer eklenmştir.
    classifier.add(Dense(4,activation="softmax")) #birden çok çıkış olduğu için softmax seçilmiştir
#    classifier.summary()
    
    epoch=10
    classifier.compile(loss='categorical_crossentropy', optimizer="adam" ,metrics=['accuracy'])
    start = timeit.default_timer() #başlangıç zamanı
    classifier.fit(trainImages,train_output, batch_size=5, epochs=epoch, verbose=0) #train işlemi için batch_size 5 seçilmiştir. input_shape=5x256x256x3 olur
    stop = timeit.default_timer() #bitiş zamanı
    print("Epoch sayısı:" , epoch)
    predictions = classifier.predict(testImages,verbose=0,batch_size=1) #test işlemleri için batch_size 1 alınmıştır.
    predictions = label_binarizer.inverse_transform(predictions)
    
    time = stop-start
    print ("Eğitim süresi: %.2f" % time,"s")
    print ("Test accuracy for ",name  ,"function: %%%.2f" % (metrics.accuracy_score(test_label,predictions)*100))
    print ("-----------------------------\n-----------------------------\n")

