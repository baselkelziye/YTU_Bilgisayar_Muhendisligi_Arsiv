#!/usr/bin/env python
# coding: utf-8
# In[1]:

#Train data okunuyor
with open("trainDec.txt") as f:
    content = f.readlines()
content = [x.strip() for x in content] 
# In[2]:
content = [x.split(",") for x in content] 

print('Toplam eğitim datası:',len(content))
# In[4]:
#Test data okunuyor
with open("testDec.txt") as f:
    contentTest = f.readlines()
contentTest = [x.strip() for x in contentTest] 
# In[5]:
contentTest = [x.split(",") for x in contentTest] 
print('Toplam test datası:',len(contentTest))
# In[6]:
knn=int(input("KNN komşu sayısını giriniz : "))
print('\n')
disMat=[]
# In[7]:
for x in contentTest:
    distance=[]
    for y in content:
        m=0
        for i in range(len(y)):
            if(x[i]!=y[i]):
                m+=1
        distance.append(m)
    disMat.append(distance)           
# In[9]:
sortDisMat=[]
for item in disMat:
    sortDisMat.append([i[0] for i in sorted(enumerate(item), key=lambda x:x[1])])
# In[11]:
#Benzerlik sayısını tutuyor
similarity=0
#Hata sayısını tutuyor
wrongsim=0
yazdir=[]
for j in range(len(contentTest)):
    nonMal=0
    mal=0
    for i in range(knn):
        if(content[sortDisMat[j][i]][531]=='NON-MALICIOUS'):
            nonMal+=1
        else:
            mal+=1
        print(content[sortDisMat[j][i]][531])

    print('-------------') 
    if(nonMal>mal):
        if(contentTest[j][531]=='NON-MALICIOUS'):
            similarity+=1
            print('->Non-MALICIOUS')
        else:
            wrongsim+=1
            print('-MALICIOUS')
    else:
        if(contentTest[j][531]=='MALICIOUS'):
            similarity+=1 
            print('->MALICIOUS')
        else:
            wrongsim+=1
            print('-Non-MALICIOUS')
			
    print('-------------')
# In[15]:
print('\n','----------------------------------\n','		KNN\n','----------------------------------\n')
print('\nKNN:',knn)
print('\nHatalı sınıflandırma sayısı=',wrongsim)
print('\nDoğru sınıflandırma sayısı=',similarity)
print('\nBaşarı oranı=',100*float(similarity/len(contentTest)),'%\n')


# In[ ]:




