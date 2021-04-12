#include<iostream>
#include<vector>
using namespace std;

int comb_one(vector<int>&v,int t,int si,string ans)
{
    if(t==0 || si==v.size())
    {
        if(t==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    count+=comb_one(v,t-v[si],si+1,ans+to_string(v[si])+" ");
    count+=comb_one(v,t,si+1,ans);
    return count;
}
int comb_inf(vector<int>&v,int t,int si,string ans)
{
    if(t==0 || si==v.size())
    {
        if(t==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    if(t<0)
    {
        return 0;
    }
    int count=0;
    count+=comb_inf(v,t-v[si],si,ans+to_string(v[si])+" ");
    count+=comb_inf(v,t,si+1,ans);
    return count;
}
int perm_inf(vector<int>&v,int t,int si,string ans)
{
    if(t==0 || si==v.size())
    {
        if(t==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    if(t<0)
    {
        return 0;
    }
    int count=0;
    count+=perm_inf(v,t-v[si],0,ans+to_string(v[si])+" ");
    count+=perm_inf(v,t,si+1,ans);
    return count;

}

int perm_one(vector<int>&v,int t,int si,string ans)
{
    if(t==0 || si==v.size())
    {
        if(t==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    if(t<0)
    {
        return 0;
    }
    int count=0;
    if(v[si]>0)
    {
        v[si]=-v[si];
      count+=perm_one(v,t+v[si],0,ans+to_string(-v[si])+" ");
       v[si]=-v[si];
    }
    count+=perm_one(v,t,si+1,ans);
    return count;

}




int main(int argc,char**argv)
{
    vector<int> v{2,3,5,7};
    int t=10;
    int ans=0;
    ans=perm_one(v,t,0,"");
    cout<<ans<<endl;
}