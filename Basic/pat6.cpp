#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cout<<"enter the number";
    cin>>n;
    int space=2*n-3;
    int val=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=n)
        {
            int t=1;
            for(int m=1;m<=val;m++)
            {
                
                cout<<t;
                t++;
            }
            for(int j=1;j<=space;j++)
            {
                cout<<" ";
            }
            for(int m=1;m<=val;m++)
            {
                t--;
                cout<<t;
                
            }
            space-=2;
            val++;
        }
        else
        {
             int x=1;
            for(int m=1;m<=2*n-1;m++)
            {
                
                cout<<x;
                if(m<=(2*n-1)/2)
                {
                    x++;
                }
                else{
                    x--;
                }
            }
        }
      cout<<endl;  
    }
}