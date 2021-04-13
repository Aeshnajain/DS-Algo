#include<iostream>
#include<vector>

using namespace std;

int main(int argc,char** argv)
{
    vector<int> v {10,20,30,40,50,60,70,80};
    int ws=3;
    int we=5;
    for(int i=0;i<v.size();i++)
    {
        for(int j=ws;j<=we;j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<endl;
        int temp=v.back();
        v.pop_back();
        v.insert(v.begin(),temp);
    }
    
}