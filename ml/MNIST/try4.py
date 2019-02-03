#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 31 17:18:51 2019

@author: vibhor
"""

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
classifier.fit(rdata,y_train,epochs = 25)

#predict
print(classifier.evaluate(rtest,y_test))
import numpy as np
img = cv2.imread('test.png',0)
img2 = img
img = np.expand_dims(img, axis = 0)
img = np.expand_dims(img,axis = 3)
ar = classifier.predict(img)
ar.shape
ar.argmax()