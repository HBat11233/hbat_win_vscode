import requests
from bs4 import BeautifulSoup

url = 'https://www.google.com/search'

hd = {'user-agent':'Chrome/10'}
some = 'baidu'
kv = {'q':some}
pxs = { 'http':'http://127.0.0.1:1080/pac?t=20190118181030057&secret=FVYKHCjdzP1z/HX+Svr+ofM1E7nUVpUeNKo+mz63oWU=',
        'https':'http://127.0.0.1:1080/pac?t=20190118181030057&secret=FVYKHCjdzP1z/HX+Svr+ofM1E7nUVpUeNKo+mz63oWU='}
r = requests.get(url,params=kv,timeout = 10,headers=hd,proxies=pxs)
r.encoding=r.status_code
print(r.raise_for_status())
print(r.text)
print(r.url)
soup = BeautifulSoup(r.text, 'html.parser')
files = open("1.html",'wb')
files.write(soup.prettify().encode("utf-8"))