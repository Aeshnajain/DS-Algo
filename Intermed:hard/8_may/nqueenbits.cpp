#include<iostream>
#include<vector>
using namespace std;

int bitsnqueen(int n,int m,int tq,int idx,int&r,int&c,int&diag,int&adiag,string ans)
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
        if((r & (1<<x))==0 && (c & (1<<y))==0 && (diag & (1<<(x+y)))==0 && (adiag & (1<<(x-y+m-1)))==0)
        {
            r^=(1<<x);
            c^=(1<<y);
            diag^=(1<<(x+y));
            adiag^=(1<<(x-y+m-1));
            count+=bitsnqueen(n,m,tq-1,i+1,r,c,diag,adiag,ans+"("+to_string(x)+","+to_string(y)+")");
            r^=(1<<x);
            c^=(1<<y);
            diag^=(1<<(x+y));
            adiag^=(1<<(x-y+m-1));
        }
    }
    return count;

}
int main(int argc,char**argv)
{
    int n=10;
    int m=10;
    int tq=10;
//    vector<bool> r;
//    vector<bool> c;
//    for(int i=0;i<n;i++)
//    {
//        r.push_back(false);
//        c.push_back(false);
//     }
//     vector<bool> diag;
//     vector<bool> adiag;
//     for(int i=0;i<n+m-1;i++)
//     {
//         diag.push_back(false);
//         adiag.push_back(false);
//     }
    int r=0;
    int c=0;
    int diag=0;
    int adiag=0;
    int count=bitsnqueen(n,m,tq,0,r,c,diag,adiag,"");
    cout<<count<<endl;
}