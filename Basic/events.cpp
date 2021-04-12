#include<iostream>
 
using namespace std;

int main( int argc, char ** argv)
{
    int e1s=2;
    int e1e=9;
    int e2s=4;
    int e2e=6;
    if(e1e<=e2s || e2e<=e1s)
    {
        cout<<"no overlap"<<endl;
    }
    else if (e1s>=e2s && e1e<=e2e || e2s>=e1s && e2e<=e1e)
    {
        cout<<"full overlap"<<endl;
    }
    else
    {
        cout<<"partial overlap"<<endl;
    }

}