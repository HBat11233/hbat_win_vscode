import requests
from bs4 import BeautifulSoup
import traceback
import re
 
def getHTMLText(url, code="utf-8"):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = code
        return r.text
    except:
        return ""

def saveHtml(url,Fpath):
    html = getHTMLText(url)
    soup = BeautifulSoup(html, 'html.parser')
    files = open(Fpath,'wb')
    files.write(soup.prettify().encode("utf-8")) 
    return ""   

def main():
    url = 'http://class.cuaa.net/paihang/news/news.jsp?information_id=135605'
    output_file = './BaiduStockInfo.html'
    saveHtml(url,output_file);
 
main()

