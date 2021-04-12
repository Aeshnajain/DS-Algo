#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
    cout<<"enter the value";
    int n;
    cin>>n;
    int t=1;
    int val=1;
    int space=n/2;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }
        for(int m=1;m<=val;m++)
        {
            cout<<t;
    
        }
        if(i<=n/2)
        {
            val+=2;
            space--;
            t++;
        }
        else
        {
            val-=2;
            space++;
            t--;
        }
        cout<<endl;
    
    }
}
