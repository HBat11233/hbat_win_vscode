#include <bits/stdc++.h>

#define PTI pair<T,int>

using namespace std;

template<typename T>
int MySearch(T arr[],int length,const T &v)
{
    vector< PTI >a;
    for(int i=0;i<length;++i)
        a.push_back(PTI(arr[i],i));
    int l=0,r=length-1;
    while(l<r)
    {
        int b=(l+r)>>1;
        PTI be=a[b];
        int tl=l,tr=r;
        while(tl<=tr)
        {
            while(a[tl].first<be.first)tl++;
            while(be.first<a[tr].first)tr--;
            if(tl<=tr)
            {
                PTI temp=a[tl];
                a[tl]=a[tr];
                a[tr]=temp;
                tl++;
                tr--;
            }
        }
        if(be.first<v)
        {
            if(tl<r)l=tl;
            else return a[tl].first==v? a[tl].second:-1;
        }
        else if(be.first>v)
        {
            if(l<tr)r=tr;
            else return a[tr].first==v? a[tr].second:-1;
        }
        else return be.second;
    }
    return -1;
}


int main()
{
    const int length=10;
    int arr[length];
    srand(time(NULL));
    for(int i=0;i<length;++i)
        arr[i]=rand()%length;
    for(int i=0;i<length;++i)
        printf("%d ",arr[i]);
    cout<<endl;
    //int ar[]={2,8,7,6,4,6,3,4,9,6};
    cout<<MySearch(arr,length,5);
    system("pause");
    return 0;
}