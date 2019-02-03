#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 31 18:16:30 2019

@author: vibhor
"""

import tensorflow as tf
import keras

from keras.models import Sequential
from keras.layers import Convolution2D
from keras.layers import MaxPooling2D
from keras.layers import Flatten
from keras.layers import Dense
from keras.layers import Dropout

(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data()
# mnist.train.images[1].shape
#  plt.imshow(mnist.train.images[1].reshape(28,28))

#x_train = x_train.reshape(x_train.shape[0],28,28,1)
#x_test = x_test.reshape(x_test.shape[0],28,28,1)
rdata = list()
for i in range((x_train.shape[0])):
    rdata.append( x_train[i].reshape(784))
    
rtest = list()
for i in range((x_test.shape[0])):
    rtest.append( x_test[i].reshape(784))    
# classifier by sequential
classifier = Sequential();
import numpy as np
x = np.array(rdata)
x.shape


# full connection
classifier.add(Dense(output_dim = 300,activation = 'relu',input_dim = 784))
classifier.add(Dropout(0.2))
classifier.add(Dense(output_dim = 100,activation = 'relu'))
classifier.add(Dropout(0.2))
classifier.add(Dense(output_dim = 70,activation = 'relu'))
classifier.add(Dropout(0.2))
classifier.add(Dense(output_dim = 50,activation = 'relu'))
classifier.add(Dropout(0.2))
classifier.add(Dense(output_dim = 25,activation = 'relu'))
classifier.add(Dropout(0.2))
classifier.add(Dense(output_dim = 10, activation = 'softmax'))

# compiling 
classifier.compile(optimizer = 'adam', loss = 'sparse_categorical_crossentropy', metrics = ['accuracy'])

# train
classifier.fit(x,y_train,epochs = 25,batch_size=200)

