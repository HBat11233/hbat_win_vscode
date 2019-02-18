#include <bits/stdc++.h>

using namespace std;

bool _c(const  int &a,const  int &b)
{
    return a>b;
}

int main()
{
    int n;
    cin>>n;
    vector <int> que(n);
    map<int, vector <int> >book;
    for(int i=0;i<n;++i)
    {
        cin>>que[i];
        book[que[i]].push_back(i+1);
    }
    sort(que.begin(),que.end(),_c);
    long long sum=0;
    for(int i=0;i<n;++i)
        sum+=que[i];
    vector <int> ans;
    if(que[0]!=que[1]&&sum-que[0]-que[1]==que[1])ans.push_back(book[que[0]][0]);
    int t = sum - que[0]*2;
    if(book.count(t)&&(!(t==que[0]&&que[0]!=que[1])))
    {
        cout<<ans.size()+book[t].size()<<'\n';
        for(int i:ans)cout<<i<<" ";
        for(int i:book[t])cout<<i<<" ";
    }
    else
    {
        cout<<ans.size()<<"\n";
        for(int i:ans)cout<<i<<' ';
    }
    return 0;
}