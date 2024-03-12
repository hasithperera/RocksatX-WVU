import numpy as np
import matplotlib.pyplot as plt


fp = open('test.bin','rb')
data = fp.read(2**20)

##
d2 = np.fromfile(file = 'test.bin', dtype=np.float32, count=-1, sep='')
plt.plot(d2)