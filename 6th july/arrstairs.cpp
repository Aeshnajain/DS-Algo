#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<string> gas(int* arr,int src,int dest)
{
    if(src==dest)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    else if(arr[src]==0)
    {
        vector<string> base;
        return base;
    }
    vector<string> ans;
    int step=arr[src];
    for(int i=1;i<=step;i++)
    {  
        if(src<dest)
       {
            int n=src+i;
          vector<string> nbr=gas(arr,n,dest);
          for(int j=0;j<nbr.size();j++)
          {
            ans.push_back(to_string(n)+nbr[j]);
          }
       } 

    }
    return ans;

}

int main(int argv,char** argc)
{
    int* arr=new int[11] {3,2,0,4,1,2,0,2,3,0,1};
    vector<string> ans=gas(arr,0,10);
       for(int i=0;i<ans.size();i++)
    {
        cout<<"0"<<ans[i]<<" ";
    }
    
}