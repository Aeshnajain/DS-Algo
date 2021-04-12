#include<iostream>
#include<vector>
using namespace std;

int combinations(vector<bool>& r,vector<bool>& q,int pq,string ans)
{
    if(pq==q.size())
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<r.size();i++)
    {
       if(r[i]==false)
       {
           r[i]=true;
           count+=combinations(r,q,pq+1,ans+"R"+to_string(i)+" Q"+to_string(pq)+" ");
           r[i]=false;
       }
    }
    return count;
}

int main(int argc,char**argv)
{
    vector<bool> r {false,false,false,false,false};
    vector<bool> q {false,false,false};
    int ans=combinations(r,q,0,"");
    cout<<ans<<endl;
}