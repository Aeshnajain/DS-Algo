#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
    cout<<"enter the number";
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
           if(m<=val/2)
           {
               t++;
           }
           else
           {
               t--;
           }
        }
        if(i<=n/2)
        { 
            t=i+1;
            val+=2;
            space--;
        }
        else
        {
            val-=2;
            space++;
        }
        cout<<endl;
    }
}