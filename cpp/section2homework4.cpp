#include <bits/stdc++.h>

using namespace std;

template<class T>
void SelectionSort(T arr[],size_t length)
{
    int pos=0;
    int cpos=pos;
    while(pos<length)
    {
        for(int i=pos+1;i<length;++i)
            if(arr[i]<arr[cpos])
                cpos=i;
        swap(arr[pos++],arr[cpos]);
            cpos=pos;
    }
}

int main()
{
    while(1)
    {
        const size_t length=30;
        int arr[length];
        srand(time(NULL));
        for(int i=0;i<length;++i)
            arr[i]=rand()%length;

        for(int i=0;i<length;++i)
            printf("%d ",arr[i]);
        cout<<endl;
            
        int a=time(NULL);
        SelectionSort(arr,length);
        int b=time(NULL);
        cout<<b-a<<endl;
        
        for(int i=0;i<length;++i)
            printf("%d ",arr[i]);
        cout<<endl;
        
       getchar();
    }
}