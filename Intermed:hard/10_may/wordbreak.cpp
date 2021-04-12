#include<iostream>
#include<vector>

using namespace std;

vector<string> v {
 "mobile","samsung","sam","sung", 
"man","mango","icecream","and", 
"go","i","like","ice","cream" 
};

bool contains(string word)
{
    for(string s:v)
    {
        if(s==word)
        {
            return true;
        }
    }
    return false;
}

int getans(string str,int idx,string ans)
{
    if(idx==str.length())
    {
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    
    for(int i=1;i<=str.length();i++)
    {
        if(idx+i<=str.length())
        {
            string word=str.substr(idx,i);
            if(contains(word))
            {
                count+=getans(str,idx+i,ans+word+" ");
            }
        }
    }
    return count;
}
int main(int argc,char**argv)
{
    string str="ilikesamsungicecreamandmango";
    int count=getans(str,0,"");
    cout<<count<<endl;
    

}