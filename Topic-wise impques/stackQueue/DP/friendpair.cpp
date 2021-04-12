#include<iostream>
#include<vector>
using namespace std;

void getans(int idx,string s,string ans,vector<bool>&vis)
{
    if(idx>=s.size())
    {
        cout<<ans<<endl;
        return;
    }
    
    
    if(vis[idx]==true)
     getans(idx+1,s,ans,vis);
    else{
    getans(idx+1,s,ans+s[idx],vis);
    for(int i=idx+1;i<s.size();i++)
    {
        if(vis[idx]==false&&vis[i]==false)
        {
            vis[i]=true;
            vis[idx]=true;
            getans(idx+1,s,ans+"{"+s[idx]+s[i]+"}",vis);
            vis[idx]=false;
            vis[i]=false;
        }
    }
    }
    
    

    
    
}

int main(int argc,char**argv)
{
    string s="ABC";
    vector<bool>vis(s.size(),false);
    getans(0,"ABC","",vis);
}