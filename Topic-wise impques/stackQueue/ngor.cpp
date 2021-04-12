#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> ngor(vector<int>&arr)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++)
    {
        while(st.size()!=1 && arr[st.top()]<arr[i])
        {
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(st.size()!=0)
    {
        int val=st.top();
        st.pop();
        ans[val]=arr.size();
    }
    return ans;

}

vector<int>gol(vector<int>& price,int n)
    {
        stack<int>st;
        vector<int>myans(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            cout<<i<<endl;
            while(st.size()>0&&price[st.top()]<price[i])
            {
                myans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
    
    vector <int> calculateSpan(vector<int>& price, int n)
    {
        vector<int>ans(n,n);
        vector<int>myans=gol(price,n);
        for(int i=0;i<ans.size();i++)
        {
            ans[i]=i-myans[i];
        }
        return ans;
       // Your code here
    }

int main(int argc,char**argv)
{
    vector<int>arr {2,4,6,1,3,4,6};
    vector<int>ans=ngor(arr);
    for(int ele:ans)
      cout<<ele<<" ";
    calculateSpan(arr,arr.size());

}