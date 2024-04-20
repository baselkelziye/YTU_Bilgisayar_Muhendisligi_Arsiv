import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd
import sys
from scipy.io.wavfile import write
from datetime import datetime

fs = 10000  # Sample rate
now = datetime.now()


#MY CONVOLUTION FUNCTION.
def Convolution(x:list, h:list,Conv_Arr:list,len_Conv:int, lenX:int, Imp_f:int):  
    for i in range(len_Conv):
        for j in range(lenX):
            if i-j >= 0 and i-j < Imp_f:
                Conv_Arr[i] += x[j]*h[i-j]
    return Conv_Arr

def FindH(h:list, Imp_f:int):
    A = 0.8    
    for i in range(Imp_f):
        h[(i + 1) * 400] = A * (i + 1)#FINDING H FUNCTION
    return h
    
def main():
    current_time = now.strftime("%H:%M:%S")
    print("Current Time =", current_time)
    duration = int(input("ENTER THE DURATION:"))# Duration of recording
    print("RECORDING... .. .\n")
    myrecording = sd.rec(int(duration * fs), samplerate=fs, channels=2)
    sd.wait()  # Wait until recording is finished
    print("RECORDING DONE.\n")
    write('myRecord.mp3', fs, myrecording)  # Save as mp3 file 
    finalArr = np.array(myrecording).flatten()
    flag  = 1
    plt.stem(finalArr,"r") 
    plt.show()
    sd.play(finalArr, fs)
    sd.wait()

    while(flag):
        Imp_f = int(input("Enter the length of the impulse response:: ")) 
        pre_h  = [0]* Imp_f * 400
        pre_h.append(0)
        pre_h[0] = 1

        h = FindH(pre_h, Imp_f)

        len_Conv = len(finalArr) + len(h) - 1
        Conv_Arr = [0]*len_Conv
        #I USED MY CONVOLUTION FUNCTION. BUT YOU CAN USE THE CONVOLUTION FUNCTION IN NUMPY:
        # Conv_Arr = np.convolve(finalArr, h)
        # THIS FUNCTION USES FOURIER TRANSFORM TO CONVOLE THE ARRAYS. SO IT IS MUCH FASTER THAN MY CONVOLUTION FUNCTION.
        Convoluted = Convolution(finalArr, h, Conv_Arr, len_Conv, len(finalArr), len(h))
        Convoluted = np.array(Convoluted, dtype=np.float32)
        write('myConvolutedRec.mp3', fs, Convoluted)
        #sd.play(myrecording, blocking = True)
        sd.play(Convoluted, fs)
        sd.wait()
        plt.stem(Convoluted,"r")
        plt.show()
        current_time = now.strftime("%H:%M:%S")
        print("Current Time =", current_time)
        flag = int(input("Enter 1 to continue, 0 to exit:"))
        if(flag != 1):
            flag = 0

#call main function 
if __name__ == '__main__':
    sys.exit(main())