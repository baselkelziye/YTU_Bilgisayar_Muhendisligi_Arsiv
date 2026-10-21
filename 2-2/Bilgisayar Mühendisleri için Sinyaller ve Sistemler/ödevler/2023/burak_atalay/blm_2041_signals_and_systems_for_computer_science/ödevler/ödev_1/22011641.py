import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd
from scipy.io import wavfile
import time

def myConv(x, start_index_x, y, start_index_y):
    m, n = len(x), len(y)
    result_length = m + n - 1
    start_index_result = start_index_x + start_index_y
    result = [0] * result_length

    for i in range(m):
        for j in range(n):
            result[i + j] += x[i] * y[j]

    return result, start_index_result

def drawStem(x, start_index_x, title):
    t = np.arange(start_index_x, len(x) + start_index_x, 1)
    plt.stem(t, x)
    plt.xlabel("time")
    plt.ylabel("amplitude")
    plt.title(title)
    plt.tight_layout()
    
def secondQuestion(x, start_index_x, y, start_index_y):
    plt.subplot(1,4,1)
    drawStem(x, start_index_x, "vector x")
    plt.subplot(1,4,2)
    drawStem(y, start_index_y, "vector y")
    plt.subplot(1,4,3)    
    result1, start_index = myConv(x, start_index_x, y, start_index_y)
    drawStem(result1, start_index, "myConv")
    plt.subplot(1,4,4)
    result2 = np.convolve(x, y, mode = "full")
    drawStem(result2, start_index, "np.convolve")
    plt.subplots_adjust(hspace=2)
    plt.show()

    print("vector x", x)
    print("vector y", y)
    print("vector myConv", result1)
    print("vector np.convolve", result2)

def recordSound(duration):
    print(f"your voice will be recorded for {duration} seconds...")
    print('Start speaking.')
    fs = 8000  # Sample rate (you can adjust this value if needed)
    recording = sd.rec(int(duration * fs), samplerate=fs, channels=1, blocking=True)
    print('End of Recording.')

    # Get recorded audio data
    x = recording.squeeze()  # Squeeze the recording to remove the channel dimension if it's a single channel

    # Save the recorded audio as a WAV file
    filename = 'recorded_audio_' + str(duration) + '.wav'
    wavfile.write(filename, fs, x)

    # Playback the recorded audio
    print('Playing back the recorded audio...')
    sd.play(x, samplerate=fs)
    sd.wait()

    return filename

def createImpulseResponse(M):
    impulseResponse = np.zeros(3000 * M + 1)
    impulseResponse[0] = 1
    A = 2
    for k in range(1, M+1):
        impulseResponse[3000 * k] = (A ** (-k)) * k

    return impulseResponse

def fourthQuestion():
    fs_read, audio_data_x1 = wavfile.read("recorded_audio_5.wav")
    audio_data_x1 = np.squeeze(audio_data_x1)
    fs_read, audio_data_x2 = wavfile.read("recorded_audio_10.wav")
    audio_data_x2 = np.squeeze(audio_data_x2)
    
    drawStem(audio_data_x1, 0, "5 seconds sound")
    # Loop over different values of M and for x1
    for M in range(3, 6):
        impulseResponse = createImpulseResponse(M)
        print("Convolution is being done for M =", M)
        
        start_time = time.time()
        result_np = np.convolve(audio_data_x1, impulseResponse)
        end_time = time.time()
        elapsed_time_np = end_time - start_time
        print("Time spent in np.convolve for M =", M, ":", elapsed_time_np, "seconds")
        result_np = np.array(result_np)
        result_np = result_np.astype(np.float32)

        start_time = time.time()
        result_my = myConv(audio_data_x1, 0, impulseResponse, 0)[0]
        end_time = time.time()
        elapsed_time_my = end_time - start_time
        print("Time spent in myConv for M =", M, ":", elapsed_time_my, "seconds")
        result_my = np.array(result_my)
        result_my = result_my.astype(np.float32)

        # Plotting
        plt.figure(figsize=(10, 10))
        
        plt.subplot(2, 1, 1) # Subplot index
        plt.title(f"M = {M} (np.convolve)")
        plt.stem(result_np, label="np.convolve")
        wavfile.write(f"recorded_audio_10_y1_np_M{M}.wav", fs_read, result_np)
        plt.legend()
        
        plt.subplot(2, 1, 2) # Subplot index
        plt.title(f"M = {M} (myConv)")
        plt.stem(result_my, label="myConv")
        wavfile.write(f"recorded_audio_5_y1_myConv_M{M}.wav", fs_read, result_np)
        plt.legend()
        plt.tight_layout()
    plt.show()

    drawStem(audio_data_x2, 0, "10 seconds sound")
    # Loop over different values of M and for x2
    for M in range(3, 6):
        impulseResponse = createImpulseResponse(M)
        print("Convolution is being done for M =", M)
        
        start_time = time.time()
        result_np = np.convolve(audio_data_x2, impulseResponse)
        end_time = time.time()
        elapsed_time_np = end_time - start_time
        print("Time spent in np.convolve for M =", M, ":", elapsed_time_np, "seconds")
        result_np = np.array(result_np)
        result_np = result_np.astype(np.float32)

        start_time = time.time()
        result_my = myConv(audio_data_x2, 0, impulseResponse, 0)[0]
        end_time = time.time()
        elapsed_time_my = end_time - start_time
        print("Time spent in myConv for M =", M, ":", elapsed_time_my, "seconds")
        result_my = np.array(result_my)
        result_my = result_my.astype(np.float32)

        # Plotting
        plt.figure(figsize=(10, 10))
        
        plt.subplot(2, 1, 1) # Subplot index
        plt.title(f"M = {M} (np.convolve)")
        plt.stem(result_np, label="np.convolve")
        wavfile.write(f"recorded_audio_5_y1_np_M{M}.wav", fs_read, result_np)
        plt.legend()
        
        plt.subplot(2, 1, 2) # Subplot index
        plt.title(f"M = {M} (myConv)")
        plt.stem(result_my, label="myConv")
        wavfile.write(f"recorded_audio_5_y1_myConv_M{M}.wav", fs_read, result_np)
        plt.legend()
        plt.tight_layout()
    plt.show()

def menu():
    print("welcome to program...")
    print("enter 1 for first question \nenter 2 for second question \nenter 3 for third question \nenter 4 for fourth question \nchoice: ")
    choice = int(input())
    if choice == 1:
        x = [2, 3, 2, 1]
        start_index_x = -1
        y = [2, -1, 1, -2]
        start_index_y = -2
        result, start_index = myConv(x, start_index_x, y, start_index_y)
        print(result)
    if choice == 2: 
        x1 = [2, 3, 2, 1]
        start_index_x1 = -1
        y1 = [2, -1, 1, -2]
        start_index_y1 = -2
        x2 = [1, 2, 3]
        start_index_x2 = 1
        y2 = [1, 2, 3]
        start_index_y2 = 1
        secondQuestion(x1, start_index_x1, y1, start_index_y1)
        secondQuestion(x2, start_index_x2, y2, start_index_y2)
    if choice == 3:
        recordSound(5)
        recordSound(10)
    if choice == 4:
        fourthQuestion()
    print("goodbye...")

menu()