#include<iostream>
//print_decreasing_and_increasing
using namespace std;
void pd(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    pd(n-1);
    cout<<n<<" ";
}

int main(int argc,char** argv)
{
   pd(5);
}