from keras.models import load_model
from tkinter import *
import tkinter as tk
import win32gui
from PIL import ImageGrab, Image
from resizeimage import resizeimage
import PIL.ImageOps    
import numpy as np
import matplotlib.pyplot as plt

model = load_model("mymodel.h5")

class_mapping = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabdefghnqrt'
def predict_digit(img):
    img = resizeimage.resize_cover(img, [28, 28])
    img = img.convert('L')
    img = np.array(img)
    plt.imshow(img, cmap = plt.get_cmap('gray'))
    plt.show()
    img = img.reshape(1,28,28,1)
    img = img/255.0
    res = model.predict([img])[0]
    print("Prediction: ",class_mapping[np.argmax(res)])
    for j in range (0,len(res)):
        if int(res[j]*100)>0:
            print(class_mapping[j], str(int(res[j]*100))+'%')
    return class_mapping[np.argmax(res)], max(res)


class App(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)
        self.x = self.y = 0
        # Creating elements
        self.canvas = tk.Canvas(self, width=300, height=300, bg = "white", cursor="cross")
        self.label = tk.Label(self, text="Thinking..", font=("Helvetica", 48))
        self.classify_btn = tk.Button(self, text = "Recognise", command =         self.classify_handwriting) 
        self.button_clear = tk.Button(self, text = "Clear", command = self.clear_all)
        # Grid structure
        self.canvas.grid(row=0, column=0, pady=2, sticky=W, )
        self.label.grid(row=0, column=1,pady=2, padx=2)
        self.classify_btn.grid(row=1, column=1, pady=2, padx=2)
        self.button_clear.grid(row=1, column=0, pady=2)
        #self.canvas.bind("<Motion>", self.start_pos)
        self.canvas.bind("<B1-Motion>", self.draw_lines)
    def clear_all(self):
        self.canvas.delete("all")
    def classify_handwriting(self):
        HWND = self.canvas.winfo_id() # get the handle of the canvas
        rect = win32gui.GetWindowRect(HWND) # get the coordinate of the canvas
        img = ImageGrab.grab(rect)
        im = PIL.ImageOps.invert(img)
        digit, acc = predict_digit(im)
        self.label.configure(text= digit+', '+ str(int(acc*100))+'%')
    def draw_lines(self, event):
        self.x = event.x
        self.y = event.y
        r=8
        self.canvas.create_oval(self.x-r, self.y-r, self.x + r, self.y + r, fill='black')
        
app = App()
mainloop()
