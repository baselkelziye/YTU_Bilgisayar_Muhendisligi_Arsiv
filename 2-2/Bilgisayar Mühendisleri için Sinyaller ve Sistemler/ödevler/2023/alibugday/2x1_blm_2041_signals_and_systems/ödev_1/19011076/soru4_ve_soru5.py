from matplotlib import pyplot as plt
import numpy as np
import wave
import wavio

from soru_1 import my_conv
from soru_3 import kaydet

graph1=kaydet(5,"ses_bes_sn.wav")
graph1_2=graph1
print("ikinci ses kaydedilmeye basladı")
graph2=kaydet(10,"ses_on_sn.wav")
graph2_2=graph2

# graph400,axis400=my_conv(graph1,[1],0,400)
# graph800,axis800=my_conv(graph1,[1],0,400)
graph400=graph1#myconv icin deger 5sn
graph800=graph1
graph400_2=np.convolve(graph1,[1])#hazır fonk icin deger 5sn
graph800_2=np.convolve(graph1,[1])


graph400_2_1=graph2#myconv icin deger 10sn
graph800_2_1=graph2
graph400_2_2=np.convolve(graph2,[1])#hazir fonk icin deger 10sn
graph800_2_2=np.convolve(graph2,[1])


#numpy array degerleri list tipine  cevirme
graph1=list(graph1)
graph1_2=list(graph1_2)
graph400=list(graph400)
graph800=list(graph800)
graph400_2=list(graph400_2)
graph800_2=list(graph800_2)

graph2=list(graph2)
graph2_2=list(graph2_2)
graph400_2_1=list(graph400_2_1)
graph800_2_1=list(graph800_2_1)
graph400_2_2=list(graph400_2_2)
graph800_2_2=list(graph800_2_2)

for i in range(4000,len(graph1)):
    graph1[i]+=graph400[i-4000]*0.4
graph1.extend(graph400[len(graph1)-4000:len(graph1)])

for i in range(8000,len(graph1)):
    graph1[i]+=graph800[i-8000]*0.4
graph1.extend(graph800[len(graph1)-8000:len(graph1)])



for i in range(4000,len(graph1_2)):
    graph1_2[i]+=graph400_2[i-4000]*0.4
graph1_2.extend(graph400_2[len(graph1_2)-4000:len(graph1_2)])

for i in range(8000,len(graph1_2)):
    graph1_2[i]+=graph800_2[i-8000]*0.4
graph1_2.extend(graph800_2[len(graph1_2)-8000:len(graph1_2)])


#on saniyelik icin fonksiyonların birbirine eklenmesi
for i in range(4000,len(graph2)):
    graph2[i]+=graph400_2_1[i-4000]*0.4
graph2.extend(graph400_2_1[len(graph2)-4000:len(graph2)])

for i in range(8000,len(graph2)):
    graph2[i]+=graph800_2_1[i-8000]*0.4
graph2.extend(graph800_2_1[len(graph2)-8000:len(graph2)])

#on saniyelik için hazır fonksiyon ile convolve edilmiş fonksiyonların birbirine eklenmesi
for i in range(4000,len(graph2_2)):
    graph2_2[i]+=graph400_2_2[i-4000]*0.4
graph2_2.extend(graph400_2_2[len(graph2_2)-4000:len(graph2_2)])

for i in range(8000,len(graph2_2)):
    graph2_2[i]+=graph800_2_2[i-8000]*0.4
graph2_2.extend(graph800_2_2[len(graph2_2)-8000:len(graph2_2)])



#numpy arraylerin ses olarak kaydedilmesi
arr = np.array(graph1)
print(type(arr))
wavio.write("soru4_myconv_bes_sn.wav", arr, 44100 , sampwidth=2)


arr = np.array(graph1_2)
print(type(arr))
wavio.write("soru4_hazir_bes_sn.wav", arr, 44100 , sampwidth=2)

arr = np.array(graph2)
print(type(arr))
wavio.write("soru4_myconv_on_sn.wav", arr, 44100 , sampwidth=2)


arr = np.array(graph2_2)
print(type(arr))
wavio.write("soru4_hazir_on_sn.wav", arr, 44100 , sampwidth=2)

print("sesler doyalara kadedildi")



# graph2,axis2=my_conv(graph2,[1],0,800)

# list1 = graph1.tolist()

# plt.subplot(2, 1, 1)
# x_values = np.linspace(0, 0 + len(graph1)-1, len(graph1))
# plt.plot(x_values, graph1)
# plt.xlabel('t')
# plt.ylabel('Amplitude');
# plt.title("5 sn  grafigi");
# plt.xlim([0, len(axis2+len(graph2))])
# plt.subplot(2, 1, 2)
# y_values = np.linspace(axis2, axis2 + len(graph2)-1, len(graph2))
# plt.plot(y_values, graph2)
#plt.xlabel('t');
# plt.ylabel('Amplitude');
# plt.title("hazir fonk grafigi");
# plt.subplots_adjust(top=0.95,
#                         bottom=0.09,
#                         left=0.1,
#                         right=0.895,
#                         hspace=0.42,
#                         wspace=0.4)
# plt.show()
# plt.close()


#
# print(len(graph1))
# print(len(graph400))
# # print(graph800[800])
# print(type(graph1))
# arr = numpy.array(graph1)
# print(type(arr))
# wavio.write("myfile.wav", arr, 44100 , sampwidth=2)




