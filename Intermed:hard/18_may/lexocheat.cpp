#include<iostream>
#include<vector>

using namespace std;
 
int main(int argc,char**argv)
{
    int n;
    cin>>n;
    vector<string> v;
    for(int i=1;i<=n;i++)
    {
        string s=to_string(i);
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
}