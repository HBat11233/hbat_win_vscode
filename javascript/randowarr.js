var arr = [];
var len = 500000;
for(var i = 0;i<len;++i)
    arr[i]=i+1;


var luan = function(arr,n,x)
{
    for(var j=0;j<x;++j)
    {
        var pos1= Math.floor(Math.random()*n);
        var pos2= Math.floor(Math.random()*n);
        var temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }
}

var print = function(arr,n)
{
    var out = "";
    for(var i=0;i<len;++i)
        out+=arr[i]+" ";
    console.log(out);
}

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

//luan(arr,len,Math.floor(len/5));
print(arr,len);
qsort(arr,0,len-1);
print(arr,len);