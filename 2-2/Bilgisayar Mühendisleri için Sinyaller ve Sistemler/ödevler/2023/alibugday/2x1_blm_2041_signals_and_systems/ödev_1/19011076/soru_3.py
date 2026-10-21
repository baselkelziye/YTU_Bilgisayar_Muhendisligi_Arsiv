import pyaudio
import numpy
import wavio

def kaydet(sure,filename):
    RATE=44100
    RECORD_SECONDS = sure
    CHUNKSIZE = 1024

    # initialize portaudio
    p = pyaudio.PyAudio()
    stream = p.open(format=pyaudio.paInt16, channels=1, rate=RATE, input=True, frames_per_buffer=CHUNKSIZE)

    frames = [] # A python-list of chunks(numpy.ndarray)
    print("ses dinleme basladi")
    for _ in range(0, int(RATE / CHUNKSIZE * RECORD_SECONDS)):
        data = stream.read(CHUNKSIZE)
        frames.append(numpy.fromstring(data, dtype=numpy.int16))

    #Convert the list of numpy-arrays into a 1D array (column-wise)
    numpydata = numpy.hstack(frames)

    print("dinleme bitti")
    # close stream
    stream.stop_stream()
    stream.close()
    p.terminate()

    #kaydetme islemi
    arr = numpy.array(numpydata)
    wavio.write(filename, arr, 44100 , sampwidth=2)

    return numpydata




if __name__ == "__main__":
    x1=kaydet(5,"ses_bes_sn.wav")
    x2=kaydet(10,"ses_on_sn.wav")
    print("sesler ses_bes_sn.waw ve ses_on_sn.waw icerisine kaydedildi")




