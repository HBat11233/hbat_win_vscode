#include <bits/stdc++.h>

using namespace std;

int binary_notlessthan(int* A, int n, int K)
{
    int l=0,r=n-1;
    while(l<r)
    {
        int b=(l+r)>>1;
        if(A[b]<K)l=b+1;
        else if(A[b]>K)r=b-1;
        else 
        {
            r=b;
            break;
        }
    }
    return (r>=0&&r<n)&&A[r]>=K? r:-1;
}

int binary_morethan(int* A, int n, int K)
{
    int l=0,r=n-1;
    while(l<r)
    {
        int b=(l+r)>>1;
        if(A[b]<K)l=b+1;
        else if(A[b]>K)r=b-1;
        else 
        {
            r=b;
            break;
        }
    }
    return (r+1>=0&&r+1<n)&&A[r+1]>=K? r+1:-1;
}

int main()
{
    srand(time(NULL));
    int a[10];
    for(int i=0;i<10;++i)
        a[i]=rand()%15;
    sort(a,a+10);
    for(int i=0;i<10;++i)
        cout<<a[i]<<' ';
    int K=rand()%15;
    cout<<endl<<K<<endl;
    cout<<binary_notlessthan(a,10,K)<<endl;
    cout<<binary_morethan(a,10,K)<<endl;
    return 0;

}