# -*- coding: utf-8 -*-


import numpy as np
import matplotlib.pyplot as plt


exp_id = 154
file_location = './data//RockSatX2024_flightData/out/{:05}_'.format(exp_id)

# /Users/hasith/Projects/Public/RocksatX-WVU/src/data-processing/data/RockSatX2024_flightData/out


exp_id = 154
time = 1
inst_id = 1
sub_time = 0

data = np.zeros([10,2**14+2])

plt.subplot(211)


for time in range(1,221,10):
    file_id = file_location + "{}_{:02}{:03}.bin".format(inst_id,sub_time,time)
    time_stamp = np.fromfile(file_id, dtype=np.intc, count=2, offset = 0)
    raw_data = np.fromfile(file_id, dtype=np.float32, count=-1, offset = 8)
    plt.plot(raw_data)

plt.title("Main experiment (exp_id=154)")

# post restart data

exp_id = 155
file_location = './data//RockSatX2024_flightData/out/{:05}_'.format(exp_id)

time = 1
inst_id = 1
sub_time = 0


plt.subplot(212)

for time in range(221,229):
    file_id = file_location + "{}_{:02}{:03}.bin".format(inst_id,sub_time,time)
    print(file_id)
    
    time_stamp = np.fromfile(file_id, dtype=np.intc, count=2, offset = 0)
    raw_data = np.fromfile(file_id, dtype=np.float32, count=-1, offset = 8)
    plt.plot(raw_data)

plt.title("after restart (exp_id=155)")