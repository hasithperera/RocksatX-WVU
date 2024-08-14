#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jun 15 20:12:16 2024

@author: hasith
"""


import numpy as np
import matplotlib.pyplot as plt


exp_id = 111
file_location = './data/exp_{}/{:05}_'.format(exp_id,exp_id)

time = 221
i = 4
k = 0

data = np.zeros([10,2**14+2])

for sub_time in range(1,11):
    file_id = file_location + "{}_{:02}{:03}.bin".format(i,sub_time,time)
    print(file_id)
    time_stamp = np.fromfile(file_id, dtype=np.intc, count=2, offset = 0)
    raw_data = np.fromfile(file_id, dtype=np.float32, count=-1, offset = 8)
    data[k,2:] = raw_data
    data[k,0] = time_stamp[0]
    data[k,1] = time_stamp[1]
    
    k = k + 1
    
    
    
print(f"total file count:{k}")

### Plotting 

for i in range(0,10):
    plt.plot(data[i,2:]+i)