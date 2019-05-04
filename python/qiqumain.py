from tkinter import *
from bs4 import BeautifulSoup

file = open('./1.html','rb')
text = str(file.read())

soup = BeautifulSoup(text,'html.parser')
myque = []
mylen = 10000000000000
cnt = 0
bol = True
for ch in soup.descendants:
        #print(ch)
        #print(ch.name)
        if ch.name is None:
            continue
        #print(len(ch.contents))
        if(bol and cnt and cnt%(mylen+1)==0):
            bol = False
            continue
        if(len(ch.contents)==1):
            #print(ch.string.replace(' ','').replace('\\n',''))
            cnt=cnt+1
            bol=True
            if(cnt%(mylen+1)==2):
                continue
            myque.append(ch.string.replace(' ','').replace('\\n',''))
            if(mylen==10000000000000 and myque[-1]=='ID'):
                mylen=len(myque)

def fun(s):
    print(s)

root = Tk()

scrollbar = Scrollbar(root)
scrollbar.pack(side=RIGHT, fill=Y)

listbox = Listbox(root, yscrollcommand=scrollbar.set)
listbox.pack(side=LEFT, fill=BOTH)

for i in range(len(myque)):
    x=i%mylen
    y=i/mylen
    b=Button(listbox,text=myque[i],command=lambda: fun(myque[i]))
    b.grid(row=int(y),column=int(x))


 
# 拉动滚动条时，改变文本域在y方向上的视图（滚动条主动关联文本域）
scrollbar.config(command=listbox.yview)
scrollbar.pack()

root.mainloop()