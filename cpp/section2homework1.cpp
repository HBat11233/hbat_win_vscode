#include <bits/stdc++.h>

using namespace std;

template<class T>
void InsertionSort(T arr[],int l,int r)
{
    int el=l,er=l;
    for(int i=l+1;i<=r;++i)
    {
        int tl=el,tr=er;
        do
        {
            int b=(tl+tr)>>1;
            if(arr[b]<arr[i])
                tr=b-1;
            else
                tl=b+1;
        }while(tl<=tr);
        if(i!=tl)
        {
            int temp=arr[i];
            for(int j=i;j>tl;--j)
            arr[j]=arr[j-1];
            arr[tl]=temp;
        }
        er++;
    }
}

int main()
{
    while(1)
    {
        const int length=100000;
        int arr[length];
        srand(time(NULL));
        for(int i=0;i<length;++i)
            arr[i]=rand()%length;/*
        for(int i=0;i<length;++i)
            printf("%d ",arr[i]);
        cout<<endl;
            */
        int a=time(NULL);
        InsertionSort(arr,0,length-1);
        int b=time(NULL);
        cout<<b-a<<endl;
        /*
        for(int i=0;i<length;++i)
            printf("%d ",arr[i]);
        cout<<endl;
        */
       getchar();
    }
    return 0;
}