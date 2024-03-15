import numpy as np
import matplotlib.pyplot as plt


#fp = open('test.bin','rb')
#data = fp.read(2**20)

##
d2 = np.fromfile(file = 'data/test-001.bin', dtype=np.float32, count=-1, sep='')
plt.plot(d2,'.-')
plt.xlim([0,100])
