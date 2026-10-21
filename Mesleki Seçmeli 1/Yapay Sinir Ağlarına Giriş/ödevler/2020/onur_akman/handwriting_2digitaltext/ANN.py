import numpy as np
import pandas as pd
import keras
from keras.utils import to_categorical
from keras.models import Sequential
from keras.layers import Conv2D, Flatten, Dense, Dropout, BatchNormalization
import matplotlib.pyplot as plt

# %%
train_data_path = 'EMNIST/emnist-balanced-train.csv'
test_data_path = 'EMNIST/emnist-balanced-test.csv'

# %%
class_mapping = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabdefghnqrt'

# %%
num_classes = 47 
img_size = 28

model = Sequential()
model.add(Conv2D(32, kernel_size = 3, activation='relu', input_shape = (img_size,img_size,1)))
model.add(BatchNormalization())
model.add(Conv2D(32, kernel_size = 3, activation='relu'))
model.add(BatchNormalization())
model.add(Conv2D(32, kernel_size = 5, strides=2, padding='same', activation='relu'))
model.add(BatchNormalization())
model.add(Dropout(0.4))

model.add(Conv2D(64, kernel_size = 3, activation='relu'))
model.add(BatchNormalization())
model.add(Conv2D(64, kernel_size = 3, activation='relu'))
model.add(BatchNormalization())
model.add(Conv2D(64, kernel_size = 5, strides=2, padding='same', activation='relu'))
model.add(BatchNormalization())
model.add(Dropout(0.4))

model.add(Conv2D(128, kernel_size = 4, activation='relu'))
model.add(BatchNormalization())
model.add(Flatten())
model.add(Dropout(0.4))
model.add(Dense(units=num_classes, activation='softmax'))

model.compile(loss='categorical_crossentropy', optimizer='Adam', metrics=['accuracy'])
model.summary()
# %%

def img_label_load(data_path, num_classes=47):
    data = pd.read_csv(data_path, header=None)
    data_rows = len(data)
    if not num_classes:
        num_classes = len(data[0].unique())
    
    # this assumes square imgs. Should be 28x28
    img_size = int(np.sqrt(len(data.iloc[0][1:])))
    
    # Images need to be transposed. This line also does the reshaping needed.
    imgs = np.transpose(data.values[:,1:].reshape(data_rows, img_size, img_size, 1), axes=[0,2,1,3]) # img_size * img_size arrays
    imgs = imgs.astype('float32')
    labels = to_categorical(data.values[:,0], num_classes) # one-hot encoding vectors
    
    return imgs/255.0, labels

# %% 
train_data = pd.read_csv(train_data_path, header=None)
test_data = pd.read_csv(test_data_path, header=None)
trainX, trainY = img_label_load(train_data_path)
testX, testY = img_label_load(test_data_path)

# %%

data_generator = keras.preprocessing.image.ImageDataGenerator(validation_split=.2,
                                            width_shift_range=.1, height_shift_range=.1,
                                            rotation_range=10, zoom_range=.1)

training_data_generator = data_generator.flow(trainX, trainY, subset='training', batch_size=64)
validation_data_generator = data_generator.flow(trainX, trainY, subset='validation', batch_size=64)

history = model.fit_generator(training_data_generator, 
                              steps_per_epoch=trainX.shape[0]//64, epochs=45, 
                              validation_data=validation_data_generator)

# %%
test_data_generator = data_generator.flow(testX, testY)
model.evaluate_generator(test_data_generator)

# %%
print(history.history.keys())

# accuracy
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.title('model accuracy')
plt.ylabel('accuracy')
plt.xlabel('epoch')
plt.legend(['train', 'validation'], loc='lower right')
plt.show()

# loss
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('model loss')
plt.ylabel('loss')
plt.xlabel('epoch')
plt.legend(['train', 'validation'], loc='upper right')
plt.show()

# %% [code]
model.save('mymodel.h5')
print("Saving the model as mymodel.h5")