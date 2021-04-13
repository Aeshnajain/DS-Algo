#include<iostream>

using namespace std;

int pow(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    int x=m*pow(m,n-1);
    return x;
}

int main(int argv,char** argc)
{
   int x= pow(5,3);
   cout<<x;
}