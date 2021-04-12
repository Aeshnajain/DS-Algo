#include<iostream>
#include<vector>
#include<string>

using namespace std;

int getansP(vector<int>&v,int t,string str,vector<int>&dp)
{
    if(t==0)
    {
        return dp[t]=1;
    }
    if(dp[t]!=-1)
    {
        return dp[t];
    }
    
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        if(t-v[i]>=0)
        {
            ans+=getansP(v,t-v[i],str+to_string(v[i])+",",dp);
        }
    }
    return dp[t]=ans;
}

int getansC(vector<int>&v,int t,int idx,vector<int>&dp)
{
    if(t==0)
    {
        return dp[t]=1;
    }
    if(dp[t]!=-1)
    {
        return dp[t];
    }
    int ans=0;
    for(int i=idx;i<v.size();i++)
    {
        if(t-v[i]>=0)
        {
            ans+=getansC(v,t-v[i],i,dp);
        }
    }
    return dp[t]=ans;
}

int main(int argc,char**argv)
{
    vector<int>v{2,3,5,7};
    int t=10;
    vector<int>dp(t+1,-1);
    cout<<getansP(v,t,"",dp)<<endl;
    //dp.resize(t+1,-1);
    //cout<<dp[t]<<endl;
    //cout<<getansC(v,t,0,dp)<<endl;
    char s=char('A'+5);
    string c="";
    c.push_back(s);
    cout<<c<<endl;
}