#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    bool arr[105];
    cin>>n;
    int ans=0;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    for(int i=1;i<n-1;++i)
    {
        if(arr[i])continue;
        if(arr[i-1]&&arr[i+1])arr[i+1]=0,ans++;
    }
    cout<<ans;
    return 0;
}