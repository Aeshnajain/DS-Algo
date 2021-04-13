#include<iostream>

using namespace std;

int pow(int m,int n)
{
    
    if(n==1)
    {
        return m;
    }
    int x;
    int pro=pow(m,n/2);
    if(n%2==0)
    {
       x=pro*pro;
      
    }
    else
    {
         x=m*pro*pro;
    }
    return x;
}

int main(int argv,char** argc)
{
   int x= pow(5,3);
   cout<<x;
}