#include <bits/stdc++.h>

using namespace std;

template <class T>
int MySearch(T arr[],int length,const T &v)
{
    for(int i=0;i<length;++i)
        if(arr[i]==v)return i;
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