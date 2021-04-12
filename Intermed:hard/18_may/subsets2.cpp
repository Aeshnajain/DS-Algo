#include<iostream>
#include<vector>

using namespace std;
void getsubsets(int check,string q,string ans,int idx,int &count)
{
    if(idx==q.size())
    {
        cout<<ans<<endl;
        return;
    }
    int mycheck=0;
    for(int i=0;i<q.size();i++)
    {
    
        int mymask=1<<(q[i]-'A');
        int mask=1<<i;
        if((mask&check)==0 && (mycheck&mymask)==0)
        {
            check^=mask;
            mycheck^=mymask;
            count=count+1;
            getsubsets(check,q,ans+q[i],idx+1,count);
            //mycheck^=mymask;
            check^=mask;
        }
    }
    
   

}
int main(int argc,char**argv)
{ 
    int count=0;
    getsubsets(0,"DB","",0,count);
    cout<<count<<endl;
}