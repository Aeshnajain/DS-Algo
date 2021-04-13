#include<iostream>

using namespace std;

//kadanes

int main(int argc,char** argv)
{
    int* arr=new int[5]{-1,3,8,2,-5,};
    int s=0; int i=0; int sum=0; int best=0; int bs=0; int be=0;
    while(s<5)
    {
        if(sum>=0)
        {
            sum=sum+arr[s];
            s++;
        }
        else
        {
            sum=arr[s];
            i=s;
            s++;
        }
        if(sum>best)
        {
            best=sum;
            bs=i;
            be=s;
        }
    }
    for(int m=bs;m<be;m++)
    {
        cout<<" "<<arr[m];
    }
    cout<<endl<<"best sum "<<best;
}