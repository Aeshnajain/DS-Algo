#include<iostream>

using namespace std;
int** takein(int r,int c)
{
    int **arr= new int*[r];
    for(int m=0;m<r;m++)
    {
        arr[m]=new int[c];
        for(int j=0;j<c;j++)
        {
            cout<<"enter the value of cell ["<<m<<","<<j<<"]"<<" ";
            cin>>arr[m][j];
        }
    }
    return arr;
    
}
void display(int** arr,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc,char** argv)
{
    int r,c;
    cout<<"enter the rows";
    cin>>r;
    cout<<"enter the columns";
    cin>>c;
    int** arr=takein(r,c);
    display(arr,r,c);
}