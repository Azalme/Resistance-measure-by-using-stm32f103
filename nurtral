#! python3

import scipy.special
import os,time
import numpy as np
#import numpy as cp
import cupy as cp


'''class defination'''
class neuralNetwork:
    #initialise network
    def __init__(self,inputnodes,hiddennodes,outputnodes,learningrate):
        self.inodes=inputnodes

        self.hnodes=hiddennodes
        self.onodes=outputnodes

        self.lr=learningrate

        self.filename_who="D:\desktop\杂项\校赛\\nurtral net data\who.txt"
        self.filename_wih="D:\desktop\杂项\校赛\\nurtral net data\wih.txt"

        self.root1='D:\desktop\杂项\校赛\data\\0\\'
        self.root2='D:\desktop\杂项\校赛\data\\2232\\'
        self.root3='D:\desktop\杂项\校赛\data\\6700\\'
        self.root4='D:\desktop\杂项\校赛\data\\13700\\'
        self.root5='D:\desktop\杂项\校赛\data\\40180\\'

        self.TestRoot='D:\desktop\杂项\校赛\data\\test\\'

        self.RealRoot='D:\desktop\杂项\校赛\data\\real\\'

        #随机获得权重矩阵
        self.wih=np.random.rand(self.hnodes,self.inodes)-0.5
        self.who=np.random.rand(self.onodes,self.hnodes)-0.5

        if os.path.exists(self.filename_who):  # 判断文件是否存在
            self.who = np.loadtxt(self.filename_who)
        else:
            pass

        if os.path.exists(self.filename_wih):
            self.wih = np.loadtxt(self.filename_wih)
        else:
            pass

        #对各各节点的输入进行sigmoid化的函数
        self.activation_funcation=lambda x:scipy.special.expit(x)

    #train network
    def train(self,inputs_list,targets_list):
        inputs=np.array(inputs_list,ndmin=2).T
        targets=np.array(targets_list,ndmin=2).T

        hidden_inputs=cp.dot(self.wih,inputs)
        hidden_outputs=self.activation_funcation(hidden_inputs)

        final_inputs=cp.dot(self.who,hidden_outputs)
        final_outputs=self.activation_funcation(final_inputs)

        #反向传播误差
        output_errors=targets-final_outputs

        hidden_errors=cp.dot(self.who.T,output_errors)

        self.who+=self.lr*cp.dot((output_errors*final_outputs*(1.0-final_outputs)),cp.transpose(hidden_outputs))
        self.wih+=self.lr*cp.dot(hidden_errors*hidden_outputs*(1.0-hidden_outputs),cp.transpose(inputs))

        pass

    #query network
    def query(self,inputs_list):
        #初始化输出为列相量
        inputs=np.array(inputs_list,ndmin=2).T

        # 矩阵点乘对输入数据进行加权(隐藏层)
        hidden_inputs = np.dot(self.wih,inputs)
        # sigmoid化(隐藏层)
        hidden_outputs = self.activation_funcation(hidden_inputs)

        # 矩阵点乘对输入数据进行加权(输出层)
        final_inputs = np.dot(self.who, hidden_outputs)
        # sigmoid化(输出层)
        final_outputs = self.activation_funcation(final_inputs)

        return final_outputs

    def storge_wih(self,dir_wih):  # 可以在外部获取权重值
        self.wih=np.loadtxt(dir_wih)
        return self.wih

    def storge_who(self,dir_who):
        self.who=np.loadtxt(dir_who)
        return self.who

    def storge_values(self):  # 将权重写入到指定的文件中来
        filename_wih = self.filename_wih

        filename_who = self.filename_who
        with open(filename_wih, 'w') as fwih:
            cp.savetxt(fwih, self.wih)

        with open(filename_who, 'w') as fwho:
            cp.savetxt(fwho, self.who)

    def DataDispose(self,dir):
        f = open(file=dir, encoding='UTF-8', mode='r')
        count = 0
        D_data = []
        while True:
            line = f.readline()
            d_count = 0
            while 1:
                D_line = line[2 + d_count:10 + d_count]
                D_data.append((round((float(D_line)-1.9)*1.4,5)))
                d_count = d_count + 10
                if d_count == 160:
                    break
            count = count + 1
            if count == 10:
                break

        return D_data       #总长度160 16*10

    def Target_Design(self,num):
        a=[]
        for i in range(0,10):
            a.append(0)
        a[num]=1
        return a

    def Input_Design(self,num,sign):
        '''
        inputs_list = []
        root = ''
        for a in range(1, 6):
            if a == 1:
                root = self.root1
            elif a == 2:
                root = self.root2
            elif a == 3:
                root = self.root3
            elif a == 4:
                root = self.root4
            elif a == 5:
                root = self.root5
            if a!=1:
                data = self.DataDispose(root + str(num) + '.txt')
                al=[]
                for b in (data[sign * 16:sign * 16 + 16]):
                    al.append(b)




                for b in al:
                    inputs_list.append(b)
            else:
                data = self.DataDispose(root + str(num) + '.txt')
                for b in (data[sign * 16:sign * 16 + 16]):
                    inputs_list.append(b)
        print(inputs_list)
        return inputs_list
        '''
        inputs_list = []
        root=''
        for a in range(1, 6):
            if a == 1:
                root = self.root1
            elif a == 2:
                root = self.root2
            elif a == 3:
                root = self.root3
            elif a == 4:
                root = self.root4
            elif a == 5:
                root = self.root5
            data =self.DataDispose(root+str(num)+'.txt')
            for b in (data[sign*16:sign*16+16]):
                inputs_list.append(b)
        #print(inputs_list)
        return inputs_list

    def RealInput_Design(self):
        real_list = []
        for a in range(1, 6):
            dir = self.RealRoot+ str(a) + '.txt'
            data = self.DataDispose(dir)
            for n in range(0, 16):
                a = 0
                for i in range(0, 10):
                    a = data[n + 16 * i] + a
                real_list.append(round(a / 10, 5))

        return real_list

    def Real_Ask(self,RealInput):
        ask_list = []
        ask_list=RealInput[:]
        final = self.query(ask_list)
        return final

    def Ask(self,num):
        ask_list=[]
        for a in range(1,6):
            dir=self.TestRoot+str(num)+'\\'+str(a)+'.txt'
            data = self.DataDispose(dir)
            for n in range(0,16):
                a = 0
                for i in range(0,10):
                    a=data[n+16*i]+a
                ask_list.append(round(a/10,5))
        #print(ask_list)
        final=self.query(ask_list)
        return final

    def Judge(self,final):
        tem = []
        for m in range(0,10):
            mm=int(final[m][0]*1000)
            tem.append(mm)
        tem2=tem[:]
        A1=max(tem)
        tem.remove(A1)
        A2=max(tem)
        tem.remove(A2)
        A3=max(tem)
        S1=tem2.index(A1)
        S2 = tem2.index(A2)
        S3 = tem2.index(A3)

        print('最可能为阻抗'+str(S1),'置信度为'+str(final[S1]))
        print('次可能为阻抗' + str(S2), '置信度为' + str(final[S2]))
        print('欠可能为阻抗' + str(S3), '置信度为' + str(final[S3]))

    def MaxMinWay(self,num,sign):
        data = []
        list1=self.Input_Design(num,sign)
        for a in range(0,5):
            list2=list1[a*16:a*16+16]
            Max=max(list2)
            Min=min(list2)
            Avr=0
            for a in list2:
                Avr=Avr+a
            Avr=Avr/len(list2)
            data.append(round(Max,3))
            data.append(round(Min,3))
            data.append(round(Avr,3))
        return data  #只有15个值

    def Ask_MMway(self,num):
        ask_list_af=[]
        ask_list = []
        for a in range(1, 6):
            dir = self.TestRoot + str(num) + '\\' + str(a) + '.txt'
            data = self.DataDispose(dir)
            for b in (data[0:16]):
                ask_list.append(b)
        for a in range(0, 5):
            list2 = ask_list[a * 16:a * 16 + 16]
            Max = max(list2)
            Min = min(list2)
            Avr = 0
            for a in list2:
                Avr = Avr + a
            Avr = Avr / len(list2)
            ask_list_af.append(round(Max, 3))
            ask_list_af.append(round(Min, 3))
            ask_list_af.append(round(Avr, 3))
        final = self.query(ask_list_af)
        return final

#确定神经网络层数
input_nodes=80
hidden_nodes=200
output_nodes=10

#确定学习率
learning_rate=0.01

n=neuralNetwork(input_nodes,hidden_nodes,output_nodes,learning_rate)

i=1
a=time.perf_counter()

while True:
    '''
    for a in range(0,10):
        for b in range(0,10):
            #n.train(inputs_list=n.MaxMinWay(b,a),targets_list=n.Target_Design(b))
            n.train(inputs_list=n.Input_Design(b, a), targets_list=n.Target_Design(b))
            #n.storge_values()
            #print('DoneB'+str(b))
        #print('DoneA'+str(a))
    n.storge_values()
    print('Done  '+str(i))
    '''

    #i=i+1
    if i==0:
        b=time.perf_counter()
        print(b-a)
        sign=input('测试阻抗:')
        if (sign=='q'):
            print('OVER')
            break
        else:
            #print(n.Ask_MMway(sign))
            #n.Judge(n.Ask_MMway(sign))
            print(n.Ask(sign))
            n.Judge(n.Ask(sign))
            #break

    print(n.Real_Ask(n.RealInput_Design()))
    n.Judge(n.Real_Ask(n.RealInput_Design()))
    break
