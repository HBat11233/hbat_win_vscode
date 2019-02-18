#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c;
    long long ans;
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>a>>b>>c;
        b=a-b;
        if(c%2)
            ans=b*(c/2)+a;
        else ans=b*(c/2);
        cout<<ans<<"\n";
    }
    return 0;
}