import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd
from scipy.io.wavfile import write
import wave
import sys
import time



def MyConv(x, y,m,n,x_zero,y_zero):
    
    convolution = np.zeros(m + n)
    
    for i in range(n):
        for j in range(m):
            convolution[i+j] += x[i] * y[j]
    
    zero_point = x_zero + y_zero    
    return convolution, zero_point


def takeSignal():
    
    x = []
    y = []
    
    n = int(input("Please enter the length of x: "))
    m = int(input("Please enter the length of y: "))

    print("Please enter the elements of x respectively:")
    for i in range(n):
        x.append(int(input()))
    
        
       
    print("Please enter the elements of y respectively:")

    for i in range(m):
        y.append(int(input()))
        
        
    x_zero = int(input("Enter the index of x[0]: "))
    y_zero = int(input("Enter the index of y[0]: "))
    MyConvResult, zero_point = MyConv(x, y, m, n,x_zero,y_zero)
    
    print("Signals:")
    print(f"x: {x}")
    print(f"y: {y}\n")
    print("MyConv result: ")
    print(MyConvResult)
    print(f"Zero point is: convolution[0] = {MyConvResult[zero_point]}\n")
    
    print("Built in function result: ")
    BuiltinFuncResult = np.convolve(x, y)
    print(BuiltinFuncResult)
    
    
    
def drawConvs(MyConvResult, zero_point, BuiltinFuncResult,x,y,x_zero,y_zero):
    axis = []
    temp = -1 * zero_point
    length = len(MyConvResult)
    for i in range(length):
        axis.append(temp)
        temp = temp + 1
    
    for i in range (0,x_zero):
        x.insert(0, 0)
        
    for i in range (len(x),length):
        x.append(0)
    
        
    for i in range (0,y_zero):
        y.insert(0, 0)
        
    for i in range (len(y),length):
        y.append(0)
        
    plt.subplot(2, 1, 1)
    plt.text(axis[0], np.min(MyConvResult)-5, "x", color='blue')
    plt.text(axis[1], np.min(MyConvResult)-5, "y", color='yellow')
    plt.text(axis[2], np.min(MyConvResult)-5, "MyConv", color='red')
    plt.stem(axis, MyConvResult, markerfmt='ro', linefmt='r-')
    plt.stem(axis, x ,markerfmt='o', linefmt='b-')
    plt.stem(axis, y ,markerfmt='o', linefmt='y-')
    
    plt.xlabel('Time')
    plt.ylabel('Amplitude')
    plt.title('Result of MyConv function')
    plt.grid(True)
    plt.xticks(np.arange(min(axis), max(axis)+1, 1))  
    plt.yticks(np.arange(min(MyConvResult), max(MyConvResult)+1, 1))  

    axis2 = []
    temp = -1 * zero_point
    length = len(BuiltinFuncResult)
    for i in range(length):
        axis2.append(temp)
        temp = temp + 1
    
    plt.subplot(2, 1, 2)
    
    plt.text(axis[0], np.min(BuiltinFuncResult)-5, "x", color='blue')
    plt.text(axis[1], np.min(BuiltinFuncResult)-5, "y", color='yellow')
    plt.text(axis[2], np.min(BuiltinFuncResult)-5, "np.convolve", color='red')
    
    plt.stem(axis2, BuiltinFuncResult ,markerfmt='ro', linefmt='r-')
    plt.stem(axis, x ,markerfmt='o', linefmt='b-')
    plt.stem(axis, y ,markerfmt='o', linefmt='y-')
    
    plt.xlabel('Time')
    plt.ylabel('Amplitude')
    plt.title('Result of np.convolve')
    plt.grid(True)
    plt.xticks(np.arange(min(axis), max(axis)+1, 1))
    plt.yticks(np.arange(min(BuiltinFuncResult), max(BuiltinFuncResult)+1, 1))

    plt.subplots_adjust(left=0.1, bottom=0.1, right=0.9, top=1.2, wspace=0.5, hspace=0.5)

    plt.show()

def testMyConv():
    
    n = 3
    x = [1,2,3]
    m = 3
    y = [1,2,3]
    x_zero = 1
    y_zero = 0
    MyConvResult = [0] * (m + n - 1)
    BuiltinFuncResult = np.convolve(x, y)
    print("Signals:")
    print(f"x: {x}")
    print(f"y: {y}\n")
    MyConvResult , zero_point = MyConv(x, y, m, n,x_zero,y_zero)
    
    print("MyConv result: ")
    print(MyConvResult)
    print(f"Zero point is: convolution[0] = {MyConvResult[zero_point]}\n")
    print("Built in function result: ")
    print(BuiltinFuncResult)
    drawConvs(MyConvResult, zero_point,BuiltinFuncResult,x,y,x_zero,y_zero)
    print("\n\n")
    n = 5
    m = 4
    x = [1,2,0,4,3]
    y = [0,1,-2,-1]
    x_zero = 1
    y_zero = 2
    MyConvResult = [0] * (m + n - 1)
    BuiltinFuncResult = np.convolve(x, y)
    print("Signals:")
    print(f"x: {x}")
    print(f"y: {y}\n")
    MyConvResult , zero_point = MyConv(x, y, m, n,x_zero,y_zero)
    print("MyConv result: ")
    print(MyConvResult)
    print(f"Zero point is: convolution[0] = {MyConvResult[zero_point]}\n")
    print("Built in function result: ")
    print(BuiltinFuncResult)
    drawConvs(MyConvResult, zero_point,BuiltinFuncResult,x,y,x_zero,y_zero)
    
    
def recordVoice(seconds):
    fs = 8000   

    print('Start speaking...')
    record = sd.rec(int(seconds * fs), samplerate=fs, channels=1,dtype='int16')
    sd.wait()
    print('End of Recording.')
    write('recording.wav', 8000 , record)




def openRecord(name):
    try:
        with wave.open(name, 'rb') as wf:
            sample_width = wf.getsampwidth()  
            frames = wf.readframes(wf.getnframes())  
          
        if sample_width == 1:
            dtype = np.uint8  
        elif sample_width == 2:
            dtype = np.int16  
        else:
            raise ValueError("Unsupported sample width")
        audio_data = np.frombuffer(frames, dtype=dtype)
        print("Here is the record in your file: ")
        playRecord(audio_data)
        return audio_data
    except FileNotFoundError:
        print("The file couldn't find")
        sys.exit(-1)



def playRecord(audio_data):
    sd.play(audio_data,samplerate=8000)
    sd.wait()




def calculateY(audio_data,M):
    y = np.zeros_like(audio_data)
    
    for n in range(0,len(audio_data)):
        sumformula = 0
        for k in range(1,M):
            if n - 3000*k >= 0:
                sumformula += 2**(-1*k) * k * audio_data[n - 3000*k]
        y[n] = audio_data[n] +sumformula
        sumformula = 0
    
    return y    





menu_flag = 10

while(menu_flag != 0):
    
    print("Welcome to my homework, please choose an option:")
    print("Enter 1 question 1 (Try MyConv with your data)")
    print("Enter 2 question 2 (Try MyConv with my sample data)")
    print("Enter 3 for question 3 and 4")
    print("Enter 0 to exit")
    menu_flag = int(input("Please enter your desicion: "))
    
    if menu_flag == 1:
        takeSignal()
        
        
    elif menu_flag == 2:
        testMyConv()
        
    elif menu_flag == 3 :
        print("\nPlease press 1 to record a voice")
        print("Please press 2 to enter a audio file name (File format must be WAV)")
        decision = int(input("Please enter your desicion: "))
        if decision == 1 :
            seconds = int(input("Please enter the duration of the recording: "))
            recordVoice(seconds)
            print("Recording successfull. Now you can find your recording in this file as 'recording.wav' ")
        elif decision == 2:
            file_name = input("Please enter the name of the file (File format must be WAV): ")
            audio_data = openRecord(file_name)
            M = int(input("Please enter the value of M: "))
            result_of_given_formula = calculateY(audio_data, M)
            print("Here is the result of given formula with your file: ")
            playRecord(result_of_given_formula)
            start_time = time.time()
            Y = np.convolve(audio_data,result_of_given_formula)
            end_time = time.time()
            print("Here is the result of the np.convolve function: ")
            time_of_built_in_func = end_time - start_time
            print(f"This operation took {time_of_built_in_func} seconds")
            playRecord(Y)
            start_time = time.time()
            myY,zero_point = MyConv(audio_data, result_of_given_formula, len(audio_data), len(result_of_given_formula), 0, 0)
            end_time = time.time()
            time_of_MyConv = end_time - start_time
            print("Here is the result of the MyConv function: ")
            print(f"This operation took {time_of_MyConv} seconds")
            playRecord(myY)
            
            
        
    elif menu_flag == 0 :
        print("Program is ending, have a nice day ")
        
    else:
        print("Invalid input please try again")

