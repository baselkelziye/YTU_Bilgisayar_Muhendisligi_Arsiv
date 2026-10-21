import tkinter as tk
from tkinter import filedialog, Text
from PIL import Image, ImageTk
import subprocess
import cv2
import os
import shutil
import numpy as np
import tensorflow as tf
import keras
import pandas as pd
from keras.models import load_model
from keras.preprocessing import image
from keras.applications.densenet import preprocess_input, decode_predictions
import math

cropped_image_label = None
run_classification_button = None
title_label = None  # Create a global title_label instance

def reset_ui():
    global title_label
    title_label.grid(row=0, column=0, columnspan=3, pady=10)

    title_label.config(text="LUTFEN ANALIZ EDILECEK GORSELI YUKLEYIN")
    result_text.delete(1.0, tk.END)
    image_label.config(image=None)
    cropped_image_label.config(image=None)
    drawed_image_label.config(image=None)
    run_classification_button.config(state=tk.DISABLED)
def run_classification(file_path, number, window):
    global title_label

    title_label.config(text="Siniflandirma Yapiliyor...")
    window.update()

    global result_text
    multiclass_dict_data = """
    1,bas_asagi
    5,bas_cevrilmis
    6,bas_yatirmis
    2,bas_yukari
    4,centik_arka
    3,centik_on
    """
    binaryclass_dict_data = """
    0,not_detected
    1,detected
    """

    binaryclass_pairs = [line.strip().split(',') for line in binaryclass_dict_data.strip().split('\n')]
    binaryclass_dict_real = {int(index): label for index, label in binaryclass_pairs}

    binary_class_dict_path = 'Binary Classification-class_dict.csv'
    binaryclass_dict = pd.read_csv(binary_class_dict_path, header=None, names=['ClassIndex', 'ClassName'])
    binaryclass_dict = dict(zip(binaryclass_dict['ClassIndex'], binaryclass_dict['ClassName']))

    binaryclassmodel_path = 'densenet169-Binary Classification-67.57.h5'
    binaryclassmodel = load_model(binaryclassmodel_path)

    #binaryclassweights_path = 'densenet169-Binary Classification-weights.h5'
    #binaryclassmodel.load_weights(binaryclassweights_path)

    mutliclass_pairs = [line.strip().split(',') for line in multiclass_dict_data.strip().split('\n')]
    multiclass_dict_real = {int(index): label for index, label in mutliclass_pairs}

    multi_class_dict_path = 'Panoramik Multiclassification-class_dict.csv'
    multiclass_dict = pd.read_csv(multi_class_dict_path, header=None, names=['ClassIndex', 'ClassName'])
    multiclass_dict = dict(zip(multiclass_dict['ClassIndex'], multiclass_dict['ClassName']))

    multiclassmodel_path = 'densenet169-Panoramik Multiclassification-45.00.h5'
    multiclassmodel = load_model(multiclassmodel_path)

   # multiclassweights_path = 'densenet169-Panoramik Multiclassification-weights.h5'
   # multiclassmodel.load_weights(multiclassweights_path)
    

    img_path = file_path
    img = image.load_img(img_path, target_size=(224, 224))
   
    img_array = image.img_to_array(img)
    
    img_array = np.expand_dims(img_array, axis=0)
    binarypredictions = binaryclassmodel.predict(img_array)

    print("binarypredictions = ", binarypredictions)
    #img_array = preprocess_input(img_array)

    #binarypredictions = binaryclassmodel.predict(img_array)

    excel_file = "Total Excel.xlsx"
    df = pd.read_excel(excel_file, header=None)

    multiclasstrue_index = 0

    for index, row in df.iterrows():
        image_filename = str(int(row[0]))
        if image_filename == number:
            binaryclasstrue_index = int(row[1])
            binaryclasstrue_label = binaryclass_dict_real[binaryclasstrue_index]
            if not math.isnan(row[2]):
                if int(row[2]) != 0:
                    multiclasstrue_index = int(row[2])
                    multiclasstrue_label = multiclass_dict_real[multiclasstrue_index]

    title_label.destroy()

    binarypredicted_index = np.argmax(binarypredictions)
    binarypredicted_label = binaryclass_dict[binarypredicted_index]

    if(binarypredicted_label == 'detected'):
        predicted_text = 'Programin Analizi: HATALI'
    else:
        predicted_text = 'Programin Analizi: HATASIZ'
    if(binaryclasstrue_label == 'detected'):
        true_text = 'Etiket Verisi: HATALI'
    else:
        true_text = 'Etiket Verisi: HATASIZ'

    result_text.configure(font=("Arial", 16))
    result_text.insert(tk.END, "\n")
    result_text.insert(tk.END, "\n")
    result_text.insert(tk.END, "\n")
    result_text.insert(tk.END, "\n")
    result_text.insert(tk.END, predicted_text)
    result_text.insert(tk.END, "\n")
    result_text.insert(tk.END, true_text)
    result_text.insert(tk.END, "\n")
    title_label = tk.Label(font=("Helvetica",10), bg="#282c34", fg="white")
    if binarypredicted_label == binaryclasstrue_label=='detected':
        multipredictions = multiclassmodel.predict(img_array)
        multipredicted_index = np.argmax(multipredictions)
        multipredicted_label = multiclass_dict[multipredicted_index]

        predictedError = ''
        if(multipredicted_label == 'centik_on'):
            predictedError = 'Centigin Onden Isirilmasi'
        elif(multipredicted_label == 'centik_arka'):
            predictedError = 'Centigin Arkadan Isirilmasi'
        elif(multipredicted_label == 'bas_yukari'):
            predictedError = 'Bas Yukari Yatirilmis'
        elif(multipredicted_label == 'bas_yatirmis'):
            predictedError = 'Bas Saga Veya Sola Yatirilmis'
        elif(multipredicted_label == 'bas_cevrilmis'):
            predictedError = 'Bas Saga Veya Sola Cevrilmis'
        elif(multipredicted_label == 'bas_asagi'):
            predictedError = 'Bas Asagi Yatirilmis'

        trueError = ''
        if(multiclasstrue_label == 'centik_on'):
            trueError = 'Centigin Onden Isirilmasi'
        elif(multiclasstrue_label == 'centik_arka'):
            trueError = 'Centigin Arkadan Isirilmasi'
        elif(multiclasstrue_label == 'bas_yukari'):
            trueError = 'Bas Yukari Yatirilmis'
        elif(multiclasstrue_label == 'bas_yatirmis'):
            trueError = 'Bas Saga Veya Sola Yatirilmis'
        elif(multiclasstrue_label == 'bas_cevrilmis'):
            trueError = 'Bas Saga Veya Sola Cevrilmis'
        elif(multiclasstrue_label == 'bas_asagi'):
            trueError = 'Bas Asagi Yatirilmis'

        result_text.insert(tk.END, f"Programin Hata Analizi: {predictedError}\n")
        if multiclasstrue_index != 0:
            result_text.insert(tk.END, f"Etiketteki Hata Tipi: {trueError}\n")
   
    shutil.rmtree('runs\segment\predict\labels')
    

def run_classification_after_crop(file_path, number, title_label,window):
    run_classification(file_path, number,window)
    run_classification_button.config(state=tk.NORMAL)  # Butonu tekrar etkinleştir

def crop(image, file, number, draw_box_on_image, window, title_label):
    global result_text
    image_path=image  # Declare result_text as a global variable
    image = cv2.imread(image)

    with open(file, 'r') as file:
        coords = file.read()

    coords = coords.split()
    coords = [float(i) for i in coords]

    x_coords = coords[1::2]
    y_coords = coords[2::2]

    height, width, _ = image.shape
    x_coords = [int(x * width) for x in x_coords]
    y_coords = [int(y * height) for y in y_coords]

    pts = []
    for i in range(len(x_coords)):
        pts.append([x_coords[i], y_coords[i]])

    pts = np.array(pts, np.int32)
    pts = pts.reshape((-1, 1, 2))

    mask = np.zeros_like(image)
    cv2.fillPoly(mask, [pts], (255, 255, 255))
    result = cv2.bitwise_and(image, mask)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

    cropped_image=f'cropped_{number}.jpg'

    cropped_image_path = os.path.join('runs', cropped_image)
    cv2.imwrite(cropped_image_path, result)
    display_image(image_path,draw_box_on_image,cropped_image_path)

    run_classification_button = tk.Button(window, text="Siniflandirma", command=lambda: run_classification_after_crop(cropped_image_path, number, title_label,window), bg="#61dafb", fg="black", width=20)
    run_classification_button.grid(row=3, column=0, columnspan=3, pady=10)

def open_file_dialog(title_label, window):
    file_path = filedialog.askopenfilename(title="Select an Image", filetypes=[("Image files", "*.png;*.jpg;*.jpeg;*.gif")])
    if file_path:
        file_name = os.path.splitext(os.path.basename(file_path))[0]
        number = file_name.split('/')[-1]
        draw_box_on_image = f"runs/segment/predict/{number}.jpg"

        title_label.config(text="Kirpma islemi yapiliyor...")
        window.update()

        run_yolo_detection(file_path)
        yolo_path = f"runs/segment/predict/labels/{number}.txt"
        crop(file_path, yolo_path, number, draw_box_on_image, window, title_label)

        title_label.config(text="Kirpma tamamlandi.", font=("Helvetica", 16), bg="#282c34", fg="white")

    return file_path

def display_image(file_path, drawed_file_path, cropped_file_path):
    image = Image.open(file_path)
    image = image.resize((352, 172)) #588, 287
    photo = ImageTk.PhotoImage(image)

    image_label.config(image=photo)
    image_label.image = photo

    drawed_image = Image.open(drawed_file_path)
    drawed_image = drawed_image.resize((352, 172))
    drawed_photo = ImageTk.PhotoImage(drawed_image)

    drawed_image_label.config(image=drawed_photo)
    drawed_image_label.image = drawed_photo


    cropped_image = Image.open(cropped_file_path)
    cropped_image = cropped_image.resize((352, 172))
    cropped_photo = ImageTk.PhotoImage(cropped_image)

    cropped_image_label.config(image=cropped_photo)
    cropped_image_label.image = cropped_photo

def run_yolo_detection(file_path):
    yolo_command = f"yolo model=best.pt mode=predict source={file_path} exist_ok=True boxes=False save_txt=True"
    try:
        result = subprocess.run(yolo_command, shell=True, check=True, capture_output=True, text=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running YOLO: {e}")
        print(f"Command output: {e.output}")
        return

    if result.returncode != 0:
        print(f"YOLO command failed with exit code {result.returncode}")
        print(f"Command output: {result.stdout}")
        print(f"Command error output: {result.stderr}")
    else:
        print("YOLO command executed successfully")

def make_user_friendly():
    global result_text, image_label, cropped_image_label, drawed_image_label, run_classification_button, title_label

    window = tk.Tk()
    window.title("Image Viewer with YOLO")
    window.configure(bg="#282c34")  # Dark theme background color

    result_text = Text(window, height=10, width=40, bg="#282c34", fg="white")
    result_text.grid(row=0, column=0, columnspan=3, padx=10, pady=10)

    button = tk.Button(window, text="Gorsel Yukle", command=lambda: open_file_dialog(title_label, window), bg="#61dafb", fg="black", width=20)
    button.grid(row=1, column=0, columnspan=3, pady=10)

    image_label = tk.Label(window, bg="#282c34")
    image_label.grid(row=2, column=0, padx=10, pady=10)
    global title_label
    title_label = tk.Label(window, text="LUTFEN ANALIZ EDILECEK GORSELI YUKLEYIN", font=("Helvetica", 10), bg="#282c34", fg="white")
    title_label.grid(row=0, column=0, columnspan=3, pady=10)

    cropped_image_label = tk.Label(window, bg="#282c34")
    cropped_image_label.grid(row=2, column=2, padx=10, pady=10)

    drawed_image_label = tk.Label(window, bg="#282c34")
    drawed_image_label.grid(row=2, column=1, padx=20, pady=10)
    global run_classification_button

    run_classification_button = tk.Button(window, text="Siniflandirma", state=tk.DISABLED, bg="#61dafb", fg="black", width=20)
    run_classification_button.grid(row=3, column=0, columnspan=3, pady=10)


    reset_button = tk.Button(window, text="Reset", command=reset_ui, bg="#ff6347", fg="black", width=20)
    reset_button.grid(row=4, column=0, columnspan=3, pady=10)

    window.mainloop()

if __name__ == "__main__":
    make_user_friendly()
