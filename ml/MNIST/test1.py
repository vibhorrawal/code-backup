#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 29 15:41:16 2019

@author: vibhor
"""
import tensorflow as tf
import keras

from keras.models import Sequential
from keras.layers import Convolution2D
from keras.layers import MaxPooling2D
from keras.layers import Flatten
from keras.layers import Dense

(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data()
# mnist.train.images[1].shape
#  plt.imshow(mnist.train.images[1].reshape(28,28))

x_train = x_train.reshape(x_train.shape[0],28,28,3)
x_test = x_test.reshape(x_test.shape[0],28,28,3)
# classifier by sequential
classifier = Sequential();
classifier.add(Convolution2D(14,3,3,input_shape = (28,28,3), activation = 'relu'))

classifier.add(MaxPooling2D(pool_size = (2,2)))
# adding layers
classifier.add(Convolution2D(14,3,3))

# pooling


# flattening
classifier.add(Flatten())

# full connection
classifier.add(Dense(output_dim = 21,activation = 'relu'))
classifier.add(Dense(output_dim = 10, activation = 'softmax'))

# compiling 
classifier.compile(optimizer = 'adam', loss = 'sparse_categorical_crossentropy', metrics = ['accuracy'])

# train
classifier.fit(x_train,y_train,epochs = 10)

#predict
classifier.evaluate(x_test,y_test)
#import numpy as np
#img = cv2.imread('test.png',0)
#img2 = img
#img = np.expand_dims(img, axis = 0)
#img = np.expand_dims(img,axis = 3)
#ar = classifier.predict(img)
#ar.shape
#ar.argmax()