#include<iostream>

using namespace std;
void swap(int* arr,int l,int r)
{
    int temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
}

void reverse(int* arr,int l,int r)
{ 
    
    while(l<r)
    {
        swap(arr,l,r);
        r--;
        l++;
    }

}


void rotate(int* arr,int n,int p)
{
    p=p%n;
    p=p<0?n+p:p;

    reverse(arr,0,n-p-1);
    reverse(arr,n-p,n-1);
    reverse(arr,0,n-1);
}
void display(int* arr,int m)
{
    for(int i=0;i<m;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(int argc,char** argv)
{
    int *arr=new int[7]{2,9,8,1,3,5,7};
    rotate(arr,7,1);
    display(arr,7);

    rotate(arr,7,22);
    display(arr,7);

    rotate(arr,7,-51);
    display(arr,7);

}