#include <iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int>arr(n,0);
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            
            int mid=(l+r)/2;
            cout<<mid<<endl;
            if(mid-1>=0 && arr[mid]==arr[mid-1])
            {
                l=mid+1;
            }
            else if(mid+1<n && arr[mid]==arr[mid+1])
            {
                r=mid-1;
            }
            else
            {
                cout<<arr[mid]<<endl;
                break;
            }
        }
    }
	//code
	return 0;
}