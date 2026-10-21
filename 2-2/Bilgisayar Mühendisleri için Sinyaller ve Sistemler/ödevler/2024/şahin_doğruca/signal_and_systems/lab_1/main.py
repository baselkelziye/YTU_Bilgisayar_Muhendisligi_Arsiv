import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd
import librosa
from scipy.signal import fftconvolve


def get_discrete_signal():

    n = int(input("Enter the number of samples: "))
    while n < 1:
        n = int(input("Enter a valid number of samples: "))

    x = {}

    for i in range(n):
        try:
            index = int(input(f"Enter the index of sample {i+1}: "))
            value = float(input(f"Enter the value of sample {i+1}: "))
            x[index] = value
        except ValueError:
            print("Invalid input. Please try again.")
            i -= 1

    return x


# myConv function that performs convolution of two discrete signals x and h are given as dictionaries
def myConv(x, h):
    y = {}
    for n in range(min(x.keys()) + min(h.keys()), max(x.keys()) + max(h.keys()) + 1):
        y[n] = 0
        for k in x.keys():
            if n - k in h.keys():
                y[n] += x[k] * h[n - k]
    return y


# myConv2 function that performs convolution of two discrete signals x and h are given as lists
def myConv2(x, h):
    len_x = len(x)
    len_h = len(h)
    len_y = len_x + len_h - 1

    y = np.zeros(len_y)

    # Reverse the impulse response for convolution
    h_reversed = h[::-1]

    # Create an array of indices for convolution
    indices = np.arange(len_y)

    # Iterate over each sample of the output signal
    for n in range(len_y):
        start = max(0, n - len_h + 1)
        end = min(len_x, n + 1)

        # Compute the convolution using array operations
        y[n] = np.sum(x[start:end] * h_reversed[indices[start:end] - n])

    return y


# compareConv function that compares the results of numpy.convolve and myConv functions


def compareConv(x, h):
    y1 = np.convolve(list(x.values()), list(h.values()))
    y2 = myConv(x, h)

    print("numpy.convolve:", y1)
    print("myConv:", y2)

    # Plot the results
    figure, axis = plt.subplots(2, 1)
    axis[0].stem(list(y1), label="numpy.convolve")
    axis[1].stem(list(y2.values()), label="myConv")

    axis[0].set_title("numpy.convolve")
    axis[1].set_title("myConv")

    plt.show()


def convolution():
    # main function that performs convolution
    print("Enter the discrete signal x[n]:")
    x = get_discrete_signal()
    print("Enter the discrete signal h[n]:")
    h = get_discrete_signal()

    y = myConv(x, h)

    print("x[n]:", x)
    print("h[n]:", h)

    compareConv(x, h)

# sound_conv function that performs convolution of an audio signal with an impulse response


def sound_conv(audio, fs, M=3, A=2):
    # Create the impulse response signal
    impulse_response = np.zeros(3000 * M + 1)
    for k in range(1, M+1):
        impulse_response[3000 * k] = A ** (-k) * k

    # Perform convolution

    output_array = fftconvolve(audio, impulse_response)
    output_array2 = myConv2(audio, impulse_response)

    # Normalize the outputs
    output_array = output_array / np.max(np.abs(output_array))
    output_array2 = output_array2 / np.max(np.abs(output_array2))

    # Play the output audios
    sd.play(output_array, fs)
    sd.wait()
    sd.play(output_array2, fs)
    sd.wait()


# Main menu
while True:
    print("1. Convolution")
    print("2. Sound convolution")
    print("3. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        convolution()
    elif choice == "2":
        audio5, fs = librosa.load("5second.mp3", sr=None, mono=True)
        audio10, fs = librosa.load("10second.mp3", sr=None, mono=True)
        sd.play(audio5, fs)
        sd.wait()
        sd.play(audio10, fs)
        sd.wait()

        sound_conv(audio5, fs, 5, 2)

        sound_conv(audio10, fs, 5, 2)
    elif choice == "3":
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please try again.")
