#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> v {
 "mobile","samsung","sam","sung", 
"man","mango","icecream","and", 
"go","i","like","ice","cream" 
};

bool contains(string w)
{
    for(string s:v)
    {
        if(s==w)
        {
            return true;
        }
    }
    return false;
}

int solve(string s,int idx,string ans,int max)
{
    if(idx==s.length())
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=1;i<=max;i++)
    {
        if(idx+i<=s.size())
        {
            string ms=s.substr(idx,i);
            if(contains(ms))
              count+=solve(s,idx+i,ans+ms+" ",max);
        }
    }
    return count;
}

int main(int argc,char**argv)
{
    string q="ilikesamsungmango";
    int max=0;
    for(string w:v)
    {
        if(w.size()>max)
        {
            max=w.size();
        }
    }
    cout<<solve(q,0,"",max)<<endl;
}
