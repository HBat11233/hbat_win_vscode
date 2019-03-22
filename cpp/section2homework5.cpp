#include <bits/stdc++.h>

using namespace std;

template <class T>
int Search(T arr[],int length,T v)
{
    int l=0,r=length-1;
    while(l<r)
    {
        int b=(l+r)>>1;
        if(arr[b]>v)
        r=b-1;
        else if(arr[b]<v)
        l=b+1;
        else return b;
    }
    return arr[l]==v? l:-1;
}

int main()
{
    const int length=30;
        int arr[length];
        srand(time(NULL));
        for(int i=0;i<length;++i)
            arr[i]=rand()%length;
        sort(arr,arr+length);
        for(int i=0;i<length;++i)
            printf("%d ",arr[i]);
        cout<<endl;
        int ans=Search(arr,length,5);
        cout<<ans<<' '<<(ans==-1? NULL:arr[ans]);
    return 0;
}