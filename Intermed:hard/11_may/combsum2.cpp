#include<iostream>
#include<vector>
using namespace std;
vector<int> coins{1,2,5,8,1,2,6,3,2,2,5,6,9,8};
void solve(int idx,int t,string ans)
{
    if(t==0)
    {
        cout<<ans<<endl;
        return;
    }
    int prev=-1;
    for(int i=idx;i<coins.size();i++)
    {
        if(prev==coins[i])
        {
            continue;
        }
        prev=coins[i];
        if(t-coins[i]>=0)
        {
            solve(i+1,t-coins[i],ans+to_string(coins[i])+" ");
        }

    }
}
int main(int argc,char**argv)
{
    sort(coins.begin(),coins.end());
    int target=8;
    solve(0,target,"");
}