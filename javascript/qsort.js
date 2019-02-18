var qsort = function (a,l,r)
{
    var b = a[(l+r)>>1];
    var tl=l;
    var tr=r;
    while(tl<=tr)
    {
        while(a[tl]<b)tl++;
        while(a[tr]>b)tr--;
        if(tl<=tr)
        {
            var temp = a[tl];
            a[tl]=a[tr];
            a[tr]=temp;
            tl++;
            tr--;
        }
    }
    if(tl<r)qsort(a,tl,r);
    if(l<tr)qsort(a,l,tr);
}

var len=50;
var arr = [];
for(var i = 0;i<len;i++)
    arr[i]=Math.floor(Math.random()*100);
var out="";
for(var i =0;i<len;++i)
    out+=arr[i]+" ";
console.log(out);
qsort(arr,0,len-1);
out="";
for(var i =0;i<len;++i)
    out+=arr[i]+" ";
console.log(out);