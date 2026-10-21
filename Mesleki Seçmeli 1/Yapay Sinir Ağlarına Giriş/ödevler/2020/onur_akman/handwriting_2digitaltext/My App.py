from keras.models import load_model
import tkinter as tk
from PIL import Image
from resizeimage import resizeimage
import numpy as np
import matplotlib.pyplot as plt
from tkinter.filedialog import askopenfilename
import cv2 as cv
import enchant
from time import perf_counter_ns 

model = load_model("mymodel.h5")
class_mapping = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabdefghnqrt'

#%% [Image processing and Letter extractor]
def readImage(filename):
    filedir = filename.replace('/', '\\')
    
    rawImg = np.array(Image.open(filedir).convert('L'))
    a = ""
    
    img = cv.cvtColor(rawImg, cv.COLOR_GRAY2BGR)
    dst4 = cv.fastNlMeansDenoisingColored(img,None,10,10,7,21)
    Image.fromarray(np.uint8(dst4)).save('NoiseEliminated.png')
	
    im = np.array(Image.open('NoiseEliminated.png').convert('L'))
    imbin = (im > 128) * 255
    Image.fromarray(np.uint8(imbin)).save('BW.png')

    flag=0
    flag2=0
    for x in range (len(imbin)):
        for y in range(len(imbin[0])):
            if imbin[x][y]==0:
                flag=1
                break
        if flag==1 and flag2==0:
            bas=x
            flag2=1
        elif flag==0 and flag2==1:
            son=x
            flaga = 0
            flagb = 0
            hbas=0
            hson=0
            blankCount=0
            for j in range(0,len(imbin[0])):
                for i in range(bas,son+1):
                    if imbin[i][j]==0:
                        flaga = 1
                        flagb = 1
                        if hbas==0:
                            hbas=j
                            if blankCount>0:
                                a += '$'
                                a+=str(blankCount)
                                a += '$'
                                blankCount=0
                if flaga==0 and flagb==1:
                    hson=j
                    im = imbin[bas:son,hbas:hson]
                    plt.imshow(im, cmap = plt.get_cmap('gray'))
                    plt.show()
                    im = (im<128)*255
                    plt.imshow(im, cmap = plt.get_cmap('gray'))
                    plt.show()
                    img = removeBlank(im)
                    plt.imshow(img, cmap = plt.get_cmap('gray'))
                    plt.show()
                    Image.fromarray(np.uint8(img)).save('letter.png')
                    a = a + getLetter()
                    flagb=0
                    hbas=0
                if (not flaga) and (hson != 0):
                    blankCount+=1
                flaga=0
            flag2=0
            a += "\n"
        flag=0
    txt = fixBlanks(a)
    txt = fixLetters(txt)
    txt = lookUp(txt)
    return(txt)  

def removeBlank(im):
    flag=0
    border1=0
    border2=len(im)
    b2s = 0
    for x in range (len(im)):
        flag2=0
        for y in range(len(im[0])):
             if (im[x][y]!=0):
                 flag2=1
        if (not flag) and flag2:
            border1=x
            flag=1
        if flag and (not flag2) and (not b2s):
            border2=x
            b2s = 1
        if flag and flag2 and b2s:
            b2s = 0
    if border1>0:
        border1 -= 1
    img = im[border1:border2,0:len(im[0])]
    return img

#%% [Letter image proccessing]   
def getLetter():
    im = cv.imread("letter.png")
    squareImage(im)
#    im = np.array(Image.open('squared_letter.png').resize((28,28)).convert('L'))
    try:
        with open('squared_letter.png', 'r+b') as f:
            with Image.open(f) as image:
                im = resizeimage.resize_cover(image, [28, 28])
        im = im.convert('L')
    except:
        im = np.array(Image.open('squared_letter.png').resize((28,28)).convert('L'))
    return (askModel(im))

def squareImage(img, background_color=0):
    x = len(img)
    y = len(img[0])
    size = max(x,y)
    size += 2
    if size<28:
        size=28
    a = np.resize(img,(size,size))
    for i in range(0,size):
        for j in range(0,size):
            a[i][j]=background_color
    if(x>y):
        k = int((size-y)/2)
        l = int((size+y)/2)
        for i in range(1,x+1):
            counter=0
            for j in range(k,l):
                a[i][j] = img[i-1][counter][0]
                counter += 1
    elif(y>x):
        k = int((size-x)/2)
        l = int((size+x)/2)
        for j in range(1,y+1):
            counter=0
            for i in range(k,l):
                a[i][j] = img[counter][j-1][0]
                counter += 1
    else:
        a = img
    Image.fromarray(np.uint8(a)).save('squared_letter.png')
    plt.imshow(a, cmap = plt.get_cmap('gray'))
    plt.show()

#%% [Predictor]      
def askModel(im): 
    im = np.array(im)
    img = im.reshape(1,28,28,1)
    plt.imshow(im, cmap = plt.get_cmap('gray'))
    plt.show()
    img = img/255.0
    
    res = model.predict([img])[0]
    char = class_mapping[np.argmax(res)]
#    print(char)
    return char

#%% [Final string editor]
def fixBlanks(txt):
#    print("Original: " + txt)
    i=0
    ntxt = ""
    while (i<len(txt)):
        intlist = []
        j=i
        while (txt[i]!='\n'):
            if txt[i]=='$':
                i+=1
                subtxt=""
                while txt[i]!='$':
                    subtxt += txt[i]
                    i+=1
                intlist.append(int(subtxt))
            i+=1
        if len(intlist)>0:
            maxx = max(intlist)
            minn = min(intlist)
            mid = (maxx+minn) / 2
            while (txt[j]!='\n'):
                if txt[j]=='$':
                   j+=1
                   subtxt=""
                   while txt[j]!='$':
                       subtxt += txt[j]
                       j+=1
                   v = int(subtxt)
                   if v>=mid:
                       ntxt+=' '
                else:
                    ntxt+=txt[j]
                j+=1
        else:
            while (txt[j]!='\n'):
                ntxt+=txt[j]
                j+=1
        ntxt+='\n'
        i+=1
#    print("Modified: " + ntxt)
    return ntxt 

def fixLetters(txt):
    ntxt = ""
    i=0
    while (i<len(txt)):
        if i>0:
            a = ord(ntxt[i-1])
            if a == ord(' '):
                a = ord(txt[i+1])
        else:
            a = ord(txt[i+1])
        b = ord(txt[i])
        if (i+1)<len(txt):
            c = ord(txt[i+1])
            if c == ord(' '):
                c = a
        else:
            c = a
        if (b==ord('0'))and((a>64)or(c>64)):
            ntxt+='o'
        elif (b==ord('5'))and((a>64)or(c>64)):
            ntxt+='s'
        elif (b<58)and(b>47)and(a>64):
            ntxt+=ntxt[i-1]
        elif (b>64)and(b<91):
            ntxt+=txt[i].lower()
        else:
            ntxt+=txt[i]
        i+=1
#    print("Modified: " + ntxt)
    return ntxt  


def lookUp(txt):
    dictionary = enchant.Dict("en_US")
    i=0
    ntxt = ""
    while (i<len(txt)):
        if ord(txt[i])>64:
            subtxt=""
            while (ord(txt[i])>64):
                subtxt+=txt[i]
                i+=1
            i-=1
            if dictionary.check(subtxt):
                ntxt+=subtxt
            else:
                sug = dictionary.suggest(subtxt)
#                print(sug)
                if len(sug)>0:
                    flag=0
                    bestScore = 0
                    bestWord=""
                    for word in sug:
                        score = 0
                        if len(word)==len(subtxt):
                            for _ in range (0, len(word)):
                                if word[_]==subtxt[_]:
                                   score+=1
                        if score>bestScore:
                            bestScore = score
                            bestWord = word
                    if bestScore:
                        ntxt += bestWord
                        flag=1
                    if not flag:
                        bestScore = 0
                        bestWord=""
                        for word in sug:
                            score = 0
                            if len(word)<len(subtxt):
                                for _ in range (0, len(word)):
                                    if word[_]==subtxt[_]:
                                        score+=1
                            if score>bestScore:
                                bestScore = score
                                bestWord = word
                        if bestScore:
                            ntxt += bestWord
                            flag=1
                    if not flag:
                        ntxt+=subtxt
                else:
                    ntxt+=subtxt  
        else:
            ntxt += txt[i]   
        i+=1
    print("\nText: " + ntxt)
    return ntxt

#%% [File path selection]   
def selectFile():
    filename = askopenfilename(title = "Select an image", filetypes=
                               (("All image files",("*.jpg","*.jpeg","*.tif","*.tiff","*.png","*.bmp")),
                                ("JPG", "*.jpg"), ("JPEG", "*.jpeg"), ("PNG", "*.png")))
    return filename

#%% [Tkinter]
class App(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)
        self.filename = ""
        # Creating elements
        self.mainText = tk.Label(self, text="Welcome. Please select an image for reading.", 
                                 font=("Helvetica", 10))
        self.button_pick = tk.Button(self, text = "Select File", command = self.select_file)
        self.classify_btn = tk.Button(self, text = "Recognise", command = self.classify_handwriting)
        # Grid structure
        self.mainText.grid(row=0, column=1, pady=5)
        self.classify_btn.grid(row=1, column=0, pady=2, padx=2)
        self.button_pick.grid(row=0, column=0, pady=2, padx=2)
    def classify_handwriting(self):
        if len(self.filename)>1:
            t0 = perf_counter_ns() 
            self.mainText.configure(text= "Processing")
            readtext = readImage(self.filename)
            with open('Text In The Image.txt', 'w') as f:
                f.write(readtext)
            self.mainText.configure(text= "Text file saved.")
            t1 = perf_counter_ns()  - t0
            print("Time elapsed: ", t1, " ns")
        else:
            self.mainText.configure(text= "Please select a file.")
    def select_file(self):
        self.filename = selectFile()
        self.mainText.configure(text= self.filename)
app = App()
app.geometry("500x100")
app.iconbitmap('myicon.ico')
app.title("Handwritten Text Recognition")
app.mainloop()

