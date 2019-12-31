#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov 18 02:03:08 2019

@author: vibhor
"""

f = open("data.csv","r")  # Outlook, temp, Humidity, Windy, Play
my_data = f.read()
data = []
lines = my_data.split()
for line in lines:
    data.append((line.split(",")))

print(data)
print("number of rows:",len(data))

def data_prep(data):
    for i in range(len(data)):
        # Outlook
        if data[i][0] == 'overcast':
            data[i][0] = 1
        elif data[i][0] == 'sunny':
            data[i][0] = 2
        else:
            data[i][0] = 3 # rainy

        # Temp
        if data[i][1] == 'hot':
            data[i][1] = 1
        elif data[i][1] == 'cool':
            data[i][1] = 2
        else: # mild
            data[i][1] = 3

        # Humidity
        if data[i][2] == 'high':
            data[i][2] = 1
        else:
            data[i][2] = 2 # normal

        # Windy
        if data[i][3] == 'FALSE':
            data[i][3] = 2
        else:
            data[i][3] = 1 # true

    return data

data = data_prep(data)
print(data)

def generate_frequency_table(data):
    # Outlook, temp, Humidity, Windy
    freq = []
    overcast_Y = 0
    sunny_Y = 0
    rainy_Y = 0
    overcast_N = 0
    sunny_N = 0
    rainy_N = 0
    for i in range(len(data)):
        if data[i][4] == 'yes':
            if data[i][0] == 1:
                overcast_Y += 1
            elif data[i][0] == 2:
                sunny_Y += 1
            else:
                rainy_Y += 1
        else:
            if data[i][0] == 1:
                overcast_N += 1
            elif data[i][0] == 2:
                sunny_N += 1
            else:
                rainy_N += 1

    outlook = [[overcast_Y, sunny_Y, rainy_Y],[overcast_N, sunny_N, rainy_N]]
    print("outlook:", outlook)
    freq.append(outlook)

    hot_Y = 0
    hot_N = 0
    cool_Y = 0
    cool_N = 0
    mild_Y = 0
    mild_N = 0
    for i in range(len(data)):
        if data[i][4] == 'yes':
            if data[i][1] == 1:
                hot_Y += 1
            elif data[i][1] == 2:
                cool_Y += 1
            else:
                mild_Y += 1
        else:
            if data[i][1] == 1:
                hot_N += 1
            elif data[i][1] == 2:
                cool_N += 1
            else:
                mild_N += 1
    temp = [[hot_Y,cool_Y,mild_Y],[hot_N,cool_N,mild_N]]
    print("temp:", temp)
    freq.append(temp)

    high_Y = 0
    high_N = 0
    normal_Y = 0
    normal_N = 0
    for i in range(len(data)):
        if data[i][4] == 'yes':
            if data[i][2] == 1:
                high_Y += 1
            else:
                normal_Y += 1
        else:
            if data[i][2] == 1:
                high_N += 1
            else:
                normal_N += 1
    weather = [[high_Y,normal_Y],[high_N,normal_N]]
    print("weather:", weather)
    freq.append(weather)

    false_Y = 0
    false_N = 0
    true_Y = 0
    true_N = 0
    for i in range(len(data)):
        if data[i][4] == 'yes':
            if data[i][3] == 1:
                true_Y += 1
            else:
                false_Y += 1
        else:
            if data[i][3] == 1:
                true_N += 1
            else:
                false_N += 2
    windy = [[true_Y,false_Y],[true_N,false_N]]
    print("windy:", windy)
    freq.append(windy)
    return freq

frequency_table = generate_frequency_table(data)
print("frequency_table:",frequency_table)

P_yes = sum([frequency_table[0][0][i] for i in range(len(frequency_table[0][0]))])
P_yes = P_yes / (P_yes + sum([frequency_table[0][1][i] for i in range(len(frequency_table[0][1]))]))
P_no = 1 - P_yes
print("P_yes:",P_yes)

def generate_likelihood_table(data):
    for k in range(4):
        for j in range(2):
            sm = sum([data[k][j][i] for i in range(len(data[k][j]))])
            #print(sm)
            for i in range(len(data[k][j])):
                data[k][j][i] = float(data[k][j][i]/sm)
    
    return data

likelihood_table = generate_likelihood_table(frequency_table)
print("likelihood_table:",likelihood_table)
inp = input("Enter Outlook,Temp,Humidity,Windy to Decide Wether to play or not:  ")
inp_data = inp.split(",")

inp_data = data_prep([inp_data])
print(inp_data)

def predict(inp_data,likelihood_table):
    yes = P_yes
    no = P_no
    for i in range(4):
        yes = yes * likelihood_table[i][0][inp_data[0][i]-1]
        no = no * likelihood_table[i][1][inp_data[0][i]-1]
    acc = yes / (yes + no)
    if yes > no:
        return "Yes", acc
    else:
        return "No", 1 - acc
    
    
print(predict(inp_data, likelihood_table))