from bs4 import BeautifulSoup
import time
from selenium import webdriver
import re

ac_que=[]

def qiqu(message):
    if(message!=0):
        ac_que.append(message)
    Fpath = './BaiduStockInfo.html'
    driver = webdriver.Chrome('./chromedriver')  # Optional argument, if not specified will search path.
    driver.get('http://acm.cqu.edu.cn/contest_show.php?cid=286#standing')
    mydriver = webdriver.Chrome('./chromedriver')
    mydriver.get('file:///D:/hbat_win_vscode/python/0.html')
    count1=0
    while True:
        time.sleep(5)
        print(count1)
        count1=count1+1
        driver.refresh()
        html=driver.page_source
        soup = BeautifulSoup(html, 'html.parser') 
        files = open(Fpath,'wb')
        files.write(soup.prettify().encode("utf-8")) 

        temp=soup.find_all('div',class_='rankcontainer')


        count=0
        for i in temp:
            files = open('.\{0}.html'.format(count),'wb')
            count=count+1
            files.write('''<style>
        .ac_stat {
            background-color: greenyellow;
        }
        .acfb_stat {
            background-color: green;
        }
        .notac_stat {
            background-color: red;
        }
    </style>'''.encode('utf-8')+i.prettify().encode('utf-8'));
        mydriver.refresh()
        try:
            s = input()
        except:
            continue
        print('s:'+s)
        time.sleep(10)
    driver.quit()
    mydriver.quit()