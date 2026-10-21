from django.shortcuts import render
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
from keras.preprocessing.image import ImageDataGenerator
from keras.utils import load_img, img_to_array
import tensorflow_addons as tfa

classes_7 = ['0_N','1_PB','2_UDH','3_FEA','4_ADH','5_DCIS','6_IC']
classes_3 = ['0_B','1_A','2_M']

def predictor(request):
    if request.method == 'POST':
        image_size = int(request.POST['image_size'])
        num_of_classes = int(request.POST['num_of_classes'])
        img_path = request.POST['img']
        modelName = request.POST['model']

        train_datagen = ImageDataGenerator(rescale = 1./255,
                                   shear_range = 0.2,
                                   zoom_range = 0.2,
                                   horizontal_flip = True)
        training_set = train_datagen.flow_from_directory(f'../new_dataset_{num_of_classes}_{image_size}/train',
                                                        target_size = (image_size, image_size),
                                                        batch_size = 32,
                                                        class_mode = 'categorical')


        model = tf.keras.models.load_model(f'../saved_models/{modelName}_{num_of_classes}_{image_size}.h5')

        model.compile(loss='categorical_crossentropy', optimizer='SGD', metrics=['accuracy', tfa.metrics.F1Score(num_classes=num_of_classes,average='macro',threshold=0.5), 
                                                                          tfa.metrics.CohenKappa(num_classes=num_of_classes)])
        
        img = load_img(f"C:/Users/ergun/Desktop/test/{img_path}", target_size=(image_size,image_size))
        img_arr = img_to_array(img) / 255.0
        pred = model.predict(np.expand_dims(img_arr, axis = 0))
        if num_of_classes == 3:
            pred_lbl = classes_3[np.argmax(pred)]
        elif num_of_classes == 7:
            pred_lbl = classes_7[np.argmax(pred)]
        score = model.evaluate(x= training_set, verbose=0)

        for i in range(4):
            print (f"{model.metrics_names[i]} : {score[i]}")

        return render(request, 'main.html', {'metrics' : model.metrics_names, 'scores' : score, 'pred' : pred_lbl, 'real' : img_path[:-4]})
    return render(request, 'main.html')