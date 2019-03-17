#include <bits/stdc++.h>

using namespace std;

class MyBit
{
private:
    vector<short>data;
    /*最少保留位数，缺省为1*/
    size_t minlength;
    /*sprit删除最高位的0,只有一位时不删除*/ 
    inline void sprit()
    {
        while(data.size()>minlength&&*data.rbegin()==0)data.pop_back();
    }
public:
    MyBit()
    :data(),minlength(1)
    {
        data.push_back(0);
        sprit();
    }
    MyBit(string data)
    :minlength(1)
    {
        for(int i=data.size()-1;i>=0;--i)
            this->data.push_back(data[i]-'0');
            sprit();
    }
    MyBit(vector<short> data)
    :data(data),minlength(1)
    {
        sprit();
    }
    int size() const
    {
        return data.size();
    }
    MyBit operator + (const MyBit & b)
    {
        vector<short>ans(max(this->size(),b.size())+1);
        int i;
        if(this->size()>b.size())
        {
            for(int i=0;i<size();++i)
                ans[i]=data[i];
            for(i=0;i<min(this->size(),b.size());++i)
            {
                ans[i]+=b.data[i];
                ans[i+1]+=ans[i]/2;
                ans[i]%=2;
            }
        }
        else
        {
            for(int i=0;i<b.size();++i)
                ans[i]=b.data[i];
            for(i=0;i<min(this->size(),b.size());++i)
            {
                ans[i]+=data[i];
                ans[i+1]+=ans[i]/2;
                ans[i]%=2;
            }
        }
        for(;i<ans.size();i++)
        {
            ans[i+1]+=ans[i]/2;
            ans[i]%=2;
        }
        return MyBit(ans);
    }
    friend ostream & operator << (ostream &out,const MyBit &b)
    {
        for(int i=b.data.size()-1;i>=0;--i)
            out<<b.data[i];
        return out;
    }
};

int main()
{
    cout<<MyBit("000000011")<<'+'<<MyBit("111101")<<'='<<MyBit("000000011")+MyBit("111101")<<endl;
    cout<<MyBit("0")<<endl;
    //cout<<MyBit("100011")+MyBit("111101");
    system("pause");
    return 0;
}