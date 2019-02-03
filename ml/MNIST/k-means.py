#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 31 13:56:24 2019

@author: vibhor
"""
import tensorflow as tf
from keras.layers import Flatten

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans
from sklearn.datasets import load_digits
from sklearn.preprocessing import scale
from sklearn.model_selection import train_test_split


(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data()

rdata = list()
for i in range((x_train.shape[0])):
    rdata.append( x_train[i].reshape(784))


dataset = load_digits()
#dataset.data.shape

data = scale(dataset.data)
#rdata = PCA(n_components=64,random_state=42).fit_transform(data)

kmeans = KMeans(n_clusters=10, init='k-means++',n_init=10, max_iter=700,tol=1e-4,precompute_distances='auto',verbose=0,random_state=None,copy_x=True,n_jobs=-1,algorithm='auto')

kmeans.fit(rdata)

ans = kmeans.predict(x_test[0:10])
print(ans)
print(y_test[0:10])
