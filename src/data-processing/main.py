import numpy as np
import matplotlib.pyplot as plt


#fp = open('test.bin','rb')
#data = fp.read(2**20)

##

avg_data = np.zeros([255])



#for i in range(0,255):
#    file = 'data/test-{:03}.bin'.format(i)
#    print(file)
#    d2 = np.fromfile(file, dtype=np.float32, count=-1, sep='')
#    
#    avg_data[i] = np.mean(d2);
    
    #plt.plot(d2,'-')
#plt.xlim([0,100])

#plt.plot(avg_data)
    
#try to load a file with time and data

# time:1718116225.793456417
file = 'data/00018_1_{:05}.bin';

for i in range(0,10):
    file_i = file.format(i)
    d1 = np.fromfile(file_i, dtype=np.intc, count=2, sep='')
    d2 = np.fromfile(file_i, dtype=np.float32, count=-1, sep='')
    print(d1)
    print(d2.shape)
    plt.plot(d2[2:],'-')