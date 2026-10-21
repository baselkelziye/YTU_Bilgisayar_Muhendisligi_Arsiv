import matplotlib.pyplot as plt
from scipy.io import wavfile
import numpy

#DTMF frequencies matrix given in PDF
mat = [[697, 1209, "1"],[697, 1336, "2"],[697, 1477, "3"],
[770, 1209, "4"],[770, 1336, "5"],[770, 1477, "6"],
[852, 1209, "7"],[852, 1336, "8"],[852, 1477, "9"],
[941, 1209, "*"],[941, 1336, "0"],[941, 1477, "#"],]

def create_audio(no):
    sample=8000
    duration=0.5
    amp=10
    time= numpy.arange(sample*duration) / sample
    flag=0
    for i in range(11):
        for j in range(11):
            if no[i]==mat[j][2]:
                freq1=mat[j][0]
                freq2=mat[j][1]
        print(f"button{no[i]}-> frequency1={freq1} frequency2={freq2}\n")
        sinus1 = amp*numpy.sin(2*numpy.pi*freq1*time)
        sinus2 = amp*numpy.sin(2*numpy.pi*freq2*time)
        sinus3 = sinus1 + sinus2
        scaled_sin = numpy.int16(sinus3 / numpy.max(numpy.abs(sinus3)) * 32767)
        if flag==0:
            son=scaled_sin
            flag=1
        else:
            son = numpy.append(son,scaled_sin)
    wavfile.write(f'{no}.wav',8000,son)


def create_num(dosya):
    sr, arr = wavfile.read(dosya)
    print(f"audio array : {arr}\n")
    print(f"\nsample rate : {sr}")
    arrs = numpy.split(arr,11)
    plt.plot(arr)
    plt.show()

    num = ""
    for i in range(11):
        plt.plot(arrs[i])
        plt.show()
        z = numpy.fft.fft(arrs[i],sr,)
        plt.plot(z)
        plt.show()
        freq1=0
        freq2=0
        k=0
        l=0
        for j in range(int(sr/2)):
            if z[j]>ed:
                if 100<j<1000:
                    freq1 = freq1 + j
                    k=k+1

                if j >1000:
                    freq2 = freq2 + j
                    l=l+1
        freq1=freq1/k
        freq2=freq2/l
        print(f"frequency1 :{freq1}")
        print(f"frequency2 :{freq2}")
        say = 0
        for m in range(11):
            if abs(mat[m][0]-freq1)<50:
                if abs(mat[m][1]-freq2)<50:
                    say = mat[m][2]
        print(f"played button :{say}\n")
        num = num + str(say)

    print(f"number in file:{num}")




#the part where I analyze the given audio file
dosya = "Ornek.wav"
ed = 3000 # eşik değer
create_num(dosya)

#creating a audio file from my phone numer
no ="05324878417"
create_audio(no)

#the part where I analyze my own created audio file
dosya = f"{no}.wav"
ed = 900000
create_num(dosya)