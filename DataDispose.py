#!python3

import scipy.fftpack
import matplotlib.pyplot as plt
import numpy as np
import pyperclip

path='D:\desktop\杂项\校赛\data\\test\\try.txt'

def DataDispose(dir=''):
    f=open(file=dir,encoding='UTF-8',mode='r')
    count=0
    D_data=[]
    while True:
        line=f.readline()
        d_count = 0
        while 1:
            D_line=line[2+d_count:10+d_count]
            D_data.append(round((float(D_line)-1.8),2))
            d_count=d_count+10
            if d_count==160:
                break
        count=count+1
        if count==10:
            break
    print(D_data[0:160])
    pyperclip.copy(str(D_data[0:160]))

    return D_data[0:160]

def list_fft():
    fft_size=80


#x=numpy.arange(0,1,99)
#plt.figure(figsize=(10,10))

#plt.ylim(0,3.4)

x=list(range(0,160))

plt.figure(figsize=(15,10))
plt.tick_params(labelsize=30)

plt.plot(x, DataDispose(path), color='orangered',  linestyle='-', label='0',linewidth=1.5)

plt.legend(fontsize=30)
plt.show()

