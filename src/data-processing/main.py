import numpy as np
import matplotlib.pyplot as plt


#fp = open('test.bin','rb')
#data = fp.read(2**20)

##

for i in range(0,255,5):
    file = 'data/test-{:03}.bin'.format(i)
    print(file)
    d2 = np.fromfile(file, dtype=np.float32, count=-1, sep='')
    plt.plot(d2,'.-')
#plt.xlim([0,100])
