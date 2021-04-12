#include<iostream>
#include<vector>
using namespace std;

int optnqueen(int n,int m,int tq,int idx,vector<bool>&r,vector<bool>&c,vector<bool>&diag,vector<bool>&adiag,string ans)
{
    if(tq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<n*m;i++)
    {
        int x=i/m;
        int y=i%m;
        if(!r[x] && !c[y] && !diag[x+y] && !adiag[x-y+m-1])
        {
            r[x]=true;
            c[y]=true;
            diag[x+y]=true;
            adiag[x-y+m-1]=true;
            count+=optnqueen(n,m,tq-1,i+1,r,c,diag,adiag,ans+"("+to_string(x)+","+to_string(y)+")");
            r[x]=false;
            c[y]=false;
            diag[x+y]=false;
            adiag[x-y+m-1]=false;
        }
    }
    return count;

}
int main(int argc,char**argv)
{
    int n=10;
    int m=10;
    int tq=10;
   vector<bool> r;
   vector<bool> c;
   for(int i=0;i<n;i++)
   {
       r.push_back(false);
       c.push_back(false);
    }
    vector<bool> diag;
    vector<bool> adiag;
    for(int i=0;i<n+m-1;i++)
    {
        diag.push_back(false);
        adiag.push_back(false);
    }
    int count=optnqueen(n,m,tq,0,r,c,diag,adiag,"");
    cout<<count<<endl;
}