import os
from skimage import io
from skimage.filters import threshold_otsu
from skimage.color import rgb2gray
from skimage.transform import resize
import numpy as np
from math import sqrt
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn import preprocessing

# =============================================================================
# 1.Özellik: Her resim için histogram değerleri çıkartılıp beyaz(255) ve siyah(0) 
#değerleri ve buna yakın olan ilk 10 değer çıkartılıp 256 değeri olan bir özellik elde edilmiştir.
#
#2. Özellik: Her resime otsu_thresholding uyguluyoruz. Otsu thresholding önplan ve arkaplan çıkarmak için
#kullanılan bir algoritmadır. Resimin değerlerine göre adaptif bir şekilde varyans hesabı yaparak thresholding uygular.
# =============================================================================
def extractFeatures(path):
    image=io.imread(path)
    bin_size=256
    features,bin_centers = np.histogram(image,bins=bin_size)
    features[0:10]=0
    features[bin_size-11:bin_size-1]=0
    features=preprocessing.normalize(np.asarray(features).reshape(-1,1))
    
    
    gray_image = rgb2gray(image)
    threshold = threshold_otsu(gray_image)  
    binary_image = gray_image > threshold
    binary_image = resize(binary_image, (sqrt(bin_size),sqrt(bin_size)),mode='constant')
    binary_image=preprocessing.normalize(np.asarray(binary_image).reshape(-1,1))
    features = np.append(features,binary_image)
    features = np.append(features,1)
                                
    return features


def loadDataSet(path):
    images=os.listdir(path)
    size=len(images)
    dataSet=[]
    for i in images:
        dataSet=np.append(dataSet,extractFeatures(path + "/" + str(i)))
            
    return dataSet,size,images

def calculateAccuracy(error):
    correct=0
    for i in error:
        if i==0:
            correct+=1
    return correct/len(error)
            
    
     
current_directory=os.getcwd()
park_dur_train_path = os.path.join(current_directory, "trafikisaretleri","egitim","parketme-durma")
tehl_uyari_train_path = os.path.join(current_directory, "trafikisaretleri","egitim","tehlike-uyari")
park_dur_test_path = os.path.join(current_directory, "trafikisaretleri","test","parketme-durma")
tehl_uyari_test_path = os.path.join(current_directory, "trafikisaretleri","test","tehlike-uyari")

trainData,size,names=loadDataSet(park_dur_train_path)
label=np.ones(size)
trainData2,size2,names2=loadDataSet(tehl_uyari_train_path)
label=np.append(label,np.zeros(size2))
size += size2
trainData=np.append(trainData,trainData2)
trainData = np.resize(trainData,(size,len(trainData)//size))

epoch=50
weights = np.random.rand(trainData.shape[1])


accuracy=[]
eta=0.01
for i in range(0,epoch):
    target = np.dot(trainData,weights)>=0
    error = label - target
    weights = weights + np.dot(np.transpose(trainData),error)*eta
#    print("Epoch number:" + str(i) + ", Error:" +  str(np.sum(error)))
    accuracy = np.append(accuracy,calculateAccuracy(error))
    
conf_matrix=metrics.confusion_matrix(label,target)
print("Confusion Matrix: \n" + str(conf_matrix))
    
plt.xlabel('Number of Epoch')
plt.ylabel('Success Rate')
plt.plot(range(0,epoch), accuracy)
plt.show()

    
















