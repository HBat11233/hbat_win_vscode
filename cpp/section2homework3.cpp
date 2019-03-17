#include <bits/stdc++.h>

using namespace std;

class MyBit
{
private:
    vector<short>data; 
public:
    MyBit()
    {}
    MyBit(string data)
    {
        for(char i:data)
            this->data.push_back(i-'0');
    }
    MyBit(vector<short> data)
    :data(data)
    {}
    int size() const
    {
        return data.size();
    }
    MyBit operator + (const MyBit & b)
    {
        vector<short>ans(max(this->size(),b.size())+1);
        for(int i=ans.size()-1;i>0;--i)
        {
            ans[i]+=data[i-1]+b.data[i-1];
            ans[i-1]+=ans[i]>>1;
            ans[i]%=2;
        }
        while(*ans.begin()==0)ans.erase(ans.begin());
        return MyBit(ans);
    }
    friend ostream & operator << (ostream &out,const MyBit &b)
    {
        for(short i:b.data)
            out<<i;
        return out;
    }
};

int main()
{
    cout<<MyBit("100011")+MyBit("111101")<<endl;
    //cout<<MyBit("100011")+MyBit("111101");
    return 0;
}