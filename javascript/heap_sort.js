var arr = [];
var str = "";

for(var i=0;i<10;i++)
    arr.push(Math.round(Math.random()*10));

Object.defineProperty(Array.prototype,"swap",
{
    enumerable:false,
    value:function (x,y)
    {
        var t = this[x];
        this[x]=this[y];
        this[y]=t;
    }
})

function max_fa(arr,start,end)
{
    var par = start;
    var son = start * 2 + 1;
    while(son<=end)
    {
        if(son < end && arr[son]<arr[son+1])son++;
        if(arr[par]>=arr[son])return;
        else
        {
            arr.swap(par,son)
            par = son;
            son = par * 2 + 1;
        }
    }
}

function sort(arr)
{
    var len = arr.length;
    for(var i = len-1;i>=0;i--)
        max_fa(arr,i,len-1);
    str = "";
    for(var i in arr)
        str += arr[i]+" ";
    console.log(str);
    for(var i = len - 1;i>0;i--)
    {
        arr.swap(0,i);
        max_fa(arr,0,i-1);
    }
    str = "";
    for(var i in arr)
        str += arr[i]+" ";
    console.log(str);
}

for(var i in arr)
    str += arr[i] + " ";
console.log(str);
sort(arr);