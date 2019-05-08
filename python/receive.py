#!/usr/bin/env python
import pika
from bs4 import BeautifulSoup
import time
from selenium import webdriver
import re
import json
import os

driver = webdriver.Chrome('./chromedriver')  # Optional argument, if not specified will search path.
driver.get('http://acm.cqu.edu.cn/contest_show.php?cid=287#standing')

#登陆
mens =driver.find_element_by_class_name('btn-navbar')
try:
    mens.click()
except:
    pass
time.sleep(0.5)
login=driver.find_element_by_id('loginbutton')
login=login.find_element_by_tag_name('a')
login.click()
time.sleep(0.5)
username = driver.find_element_by_id('username')
username.send_keys('cqupc19_150')
time.sleep(0.5)
password = driver.find_element_by_id('password')
password.send_keys('ATfCRtbr')
time.sleep(0.5)
login=driver.find_element_by_id('logindialog')
login=login.find_element_by_name('login')
login.click()
time.sleep(4)
settings=driver.find_element_by_id('cset_a')
settings.click()
time.sleep(0.5)
settings=driver.find_element_by_name('shownum')
settings.click()
time.sleep(0.5)
login=driver.find_element_by_id('csetform')
login=login.find_element_by_name('login')
login.click()
time.sleep(0.5)


mydriver = webdriver.Chrome('./chromedriver')
mydriver.get('file:///{0}/0.html'.format(os.getcwd()))
ac_que=[]
file_name = 'ac_que.json' #通过扩展名指定文件存储的数据为json格式
with open(file_name,'r') as file_object:
    ac_que = json.load(file_object)

connection = pika.BlockingConnection(
    pika.ConnectionParameters(host='localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello')


def callback(ch, method, properties, body):
    global ac_que
    print(" [x] Received %r" % body)
    print(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))
    if(body!=b'0'):
        ac_que.append(str(body,encoding='utf-8'))
    print(ac_que)
    with open(file_name,'w') as file_object:
        json.dump(ac_que,file_object)
    driver.refresh()
    time.sleep(1)
    clickuser=driver.find_element_by_id('stat_dis_user')
    clickuser.click()
    time.sleep(0.5)
    html=driver.page_source
    soup = BeautifulSoup(html, 'html.parser')
    temp=soup.find_all('div',class_='rankcontainer')
    count=0
    for i in temp:
        files = open('.\{0}.html'.format(count),'wb')
        count=count+1

        text = i.prettify()
        for j in ac_que:
            try:
                index=text.index(j)
                if(len(j)<8):
                    raise RuntimeError('message<8')
            except:
                ac_que=ac_que[:ac_que.index(j)]+ac_que[ac_que.index(j)+1:]
                continue
            length=len(j)
            text=text[:index-12]+text[index-10:index]+text[index+length:]
        text = '''<style>
    .ac_stat {
        background-color: greenyellow;
    }
    .acfb_stat {
        background-color: green;
    }
    .notac_stat {
        background-color: red;
    }
</style>'''.encode('utf-8')+text.encode('utf-8')
        files.write(text)
        files.close()
    mydriver.refresh()


channel.basic_consume(
    queue='hello', on_message_callback=callback, auto_ack=True)

print(' [*] Waiting for messages. To exit press CTRL+C')
channel.start_consuming()