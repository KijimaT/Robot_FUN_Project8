# -*- coding:utf-8 -*-
import socket
import serial
import re
import string
from tuning import Tuning
import usb.core
import usb.util

julius=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
julius.connect(('localhost',10500))

processing=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
processing.connect(('localhost',8123))

ser=serial.Serial('/dev/ttyACM0',9600)

dev=usb.core.find(idVendor=0x2886, idProduct=0x0018)

if dev:
    Mic_tuning = Tuning(dev)

re_word=re.compile('WORD="([^"]+)')
cm_word=re.compile('CM="([^"]+)')
data=''

try:
    while True:
        while(data.find('</RECOGOUT>\n.')==-1):
          data+=str(julius.recv(1024).decode('utf-8'))
        
        recog_text=''
        for word in filter(bool,re_word.findall(data)):
            recog_text+=word
        
        cm_list=[]
        for cm in filter(bool,cm_word.findall(data)):
            cm_list.append(cm)

        if recog_text.find('こっち向いて')>0 and (float(cm_list[1]))>0.9:
            ser_send='A,'+str(Mic_tuning.direction)
            ser.write(bytes(ser_send,'utf-8'))
            processing.send('kottimuite'.encode('utf-8'))
        elif recog_text.find('頷いて')>0 and (float(cm_list[1]))>0.9:
            ser_send='B,1'
            ser.write(bytes(ser_send,'utf-8'))
            processing.send('unazuite'.encode('utf-8'))
        elif recog_text.find('口開けて')>0 and (float(cm_list[1]))>0.9:
            ser_send='C,1'
            ser.write(bytes(ser_send,'utf-8'))
            processing.send('kutiakete'.encode('utf-8'))
        elif recog_text.find('口閉じて')>0 and (float(cm_list[1]))>0.9:
            ser_send='C,0'
            ser.write(bytes(ser_send,'utf-8'))
            processing.send('kutitojite'.encode('utf-8'))
        elif recog_text.find('尻尾振って')>0 and (float(cm_list[1]))>0.9:
            ser_send='D,1'
            ser.write(bytes(ser_send,'utf-8'))
            processing.send('sippohutte'.encode('utf-8'))
        elif recog_text.find('尻尾止めて')>0 and (float(cm_list[1]))>0.9:
            ser_send='D,0'
            ser.write(bytes(ser_send,'utf-8'))
            processing.send('sippotomete'.encode('utf-8'))
        
        print(recog_text)
        print(Mic_tuning.direction)
        print(cm_list[1])
        data=""

except KeyboardInterrupt:
    print('END')
#    julius.send(b'DIE')
    julius.close()
    processing.close()