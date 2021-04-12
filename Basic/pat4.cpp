#include<iostream>
using namespace std;
int main(int argc,char** argv)
{
    cout<<"enter the number";
    int n;
    cin>>n;
    int val=1;
    int space=n/2;
    int t=1;
    for (int i=1;i<=n+1;i++)
    {   
        for(int j=1;j<=space;j++)
        {
            cout<<" ";
        }
        for(int m=1;m<=val;m++)
        {
            cout<<t;
            t++;
        }
        if(i<=n/2)
        {
            val+=2;
            space--;
            t=i+1;
        }
        else
        {
            val-=2;
            space++;
             t=t/3;
        }
        cout<<endl;
    }
}