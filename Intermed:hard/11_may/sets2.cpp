#include<iostream>
#include<vector>
using namespace std;
vector<int> v{10,20,30,40,50,60,70,80};
int check=0;

int solve(int idx,int sum1,int sum2,string s1,string s2)
{
    if(idx==v.size())
    {
        if(sum1==sum2)
        {
            cout<<s1<<endl<<s2<<endl;
            return 1;
        }
        return 0;
    }

    int count=0;
    count+=solve(idx+1,sum1+v[idx],sum2,s1+to_string(v[idx])+" ",s2);
    count+=solve(idx+1,sum1,sum2+v[idx],s1,s2+to_string(v[idx])+" ");
    return count;

}

int main(int argc,char**argv)
{
   //int c=solve(0,0,0,"","");
   //to avoid duplicacy
   int c=solve(1,10,0,"10 ","");
   cout<<c<<endl;
}