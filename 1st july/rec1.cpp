#include<iostream>

using namespace std;
void pd(int n)
{
    if(n==0)
    {
        return;
    }
    pd(n-1);
    cout<<n<<" ";
}

int main(int argc,char** argv)
{
   pd(5);
}