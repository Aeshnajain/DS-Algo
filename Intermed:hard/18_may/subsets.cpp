#include<iostream>
#include<vector>

using namespace std;
void getsubsets(int check,string q,string ans,int idx)
{
    if(idx==q.size())
    {
        cout<<ans<<endl;
        return;
    }
    int mycheck=0;
    int mymask=1<<(q[idx]-'a');
    int mask=1<<idx;
    if((mask&check)==0 && (mycheck&mymask)==0)
    {
        check^=mask;
        mycheck^=mymask;
        getsubsets(check,q,ans+q[idx],0);
        check^=mask;
    }
    if((mycheck&mymask)==0)
    {
        //mycheck^=mymask;
      getsubsets(check,q,ans,idx+1);
      //mycheck^=mymask;
    }
   

}
int main(int argc,char**argv)
{
    getsubsets(0,"aabc","",0);
}