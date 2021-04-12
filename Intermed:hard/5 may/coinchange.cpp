#include<iostream>
#include<vector>
using namespace std;

int perm_inf(vector<int>&v,int t,string ans)
{
    if(t==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int ele : v)
    {
        if(t-ele>=0)
        {
            count+=perm_inf(v,t-ele,ans+to_string(ele)+" ");
        }
    }
    return count;
}

int comb_inf(vector<int>&v,int t,int si,string ans)
{
    if(t==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=si;i<v.size();i++)
    {
        if(t-v[i]>=0)
        {
            count+=comb_inf(v,t-v[i],i,ans+to_string(v[i])+" ");
        }
    }
    return count;
}

int comb_one(vector<int>&v,int t,int si,string ans)
{
    if(t==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=si+1;i<v.size();i++)
    {
        if(t-v[i]>=0)
        {
            count+=comb_one(v,t-v[i],i,ans+to_string(v[i])+" ");
        }
    }
    return count;
}

int perm_one(vector<int>&v,int t,vector<bool> c,string ans)
{
    if(t==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        if(c[i]==false && t-v[i]>=0)
        {
            c[i]=true;
            count+=perm_one(v,t-v[i],c,ans+to_string(v[i])+" ");
            c[i]=false;
        }
    }
    return count;
}

int main(int argc,char**argv)
{
    vector<int> v{2,3,5,7};
    int t=10;
    int ans=0;
    //ans=perm_inf(v,t,"");
    //ans=comb_inf(v,t,0,"");
    //ans=comb_one(v,t,-1,"");
    vector<bool> check{false,false,false,false};
    ans=perm_one(v,t,check,"");
    cout<<ans<<endl; 
}