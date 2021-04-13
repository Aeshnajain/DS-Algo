#include<iostream>
#include<vector>

using namespace std;

bool odd(int num)
{
    if(num%2==1)
    {
       return true;
    }
    else
    {
        return false;
    }
}
vector<int> check(int n)
{
    vector<int> res;

    for(int i=0;i<n;i++)
    {
        int num;
        cout<<"enter the value ";
        cin>>num;
        bool flag=odd(num);
        if(flag==true)
        {
            res.push_back(num);
        }
    }
    return res;

}

int main(int args,char** argv)
{
    int n;
    cout<<"enter the count of numbers";
    cin>>n;

    vector<int> v = check(n);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

}