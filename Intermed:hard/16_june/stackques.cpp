#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> ngor(vector<int>&v)
{
    vector<int> ans(v.size(),v.size());
    stack<int> st;
    for(int i=0;i<v.size();i++)
    {
        while(st.size()!=0 && v[st.top()]<v[i])
        {
            int idx=st.top();
            st.pop();
            ans[idx]=i;
        }
        st.push(i);
    }
    return ans;
}

vector<int> nsor(vector<int>&v)
{
    vector<int> ans(v.size(),v.size());
    stack<int> st;
    for(int i=0;i<v.size();i++)
    {
        while(st.size()!=0 && v[st.top()]>v[i])
        {
            int idx=st.top();
            st.pop();
            ans[idx]=i;
        }
        st.push(i);
    }
    return ans;
}

vector<int> ngol(vector<int>&v)
{
    vector<int> ans(v.size(),v.size());
    stack<int> st;
    for(int i=v.size()-1;i>-1;i--)
    {
        while(st.size()!=0 && v[st.top()]<v[i])
        {
            int idx=st.top();
            st.pop();
            ans[idx]=i;
        }
        st.push(i);
    }
    return ans;
}

void remOuterbrackets(string s)
{
    int count=0;
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==')')
        {
           count++;
           if(count>1)
           {
               ans+=s[i];
           }
        }
        else
        {
            count--;
            if(count>=1)
            {
                ans+=s[i];
            }
        }
        
    }
}


//84. Largest Rectangle in Histogram

 int largestRectangleArea(vector<int>& heights) 
{
    stack<int> st;
    int max=0;
    st.push(-1);
    for(int i=0;i<heights.size();i++)
    {
        while(st.top()!=-1 && heights[st.top()]>=heights[i])
        {
            int h=heights[st.top()];
            st.pop();
            int b=i-st.top()-1;
            max=max>h*b?max:h*b;
            
        }
        st.push(i);
    }
    while(st.size()>1)
    {
        int h=heights[st.top()];
        st.pop();
        int b=heights.size()-st.top()-1;
            max=max>h*b?max:h*b;
    }
    return max;
        
}

//85. Maximal Rectangle
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max=0;
        st.push(-1);
        for(int i=0;i<heights.size();i++)
        {
            while(st.top()!=-1 && heights[st.top()]>=heights[i])
            {
                int h=heights[st.top()];
                st.pop();
                int b=i-st.top()-1;
                max=max>h*b?max:h*b;
                
            }
            st.push(i);
        }
        while(st.size()>1)
        {
            int h=heights[st.top()];
            st.pop();
            int b=heights.size()-st.top()-1;
             max=max>h*b?max:h*b;
        }
        return max;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
        {
            return 0;
        }
        vector<int> heights (matrix[0].size(),0);
        int m=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int val=matrix[i][j]-'0';
                if(val==1)
                {
                    heights[j]++;
                }
                else 
                {
                    heights[j]=0;
                }
            }
            m=m>largestRectangleArea(heights)?m:largestRectangleArea(heights);
            
        }
       return m; 
        
    }
};

//42. Trapping Rain Water

int trap01(vector<int>& height) {
        if(height.size()<2)
        {
            return 0;
        }
        vector<int> maxleft(height.size(),0);
        vector<int> maxright(height.size(),0);
        
        for(int i=0;i<maxleft.size();i++)
        {
            if(i==0)
            {
                maxleft[i]=height[i];
            }
            else
            {
                maxleft[i]=maxleft[i-1]>height[i]?maxleft[i-1]:height[i];
            }
        }
        for(int i=maxright.size()-1;i>=0;i--)
        {
            if(i==maxright.size()-1)
            {
                maxright[i]=height[i];
            }
            else
            {
                maxright[i]=maxright[i+1]>height[i]?maxright[i+1]:height[i];
            }
        }
        int ta=0;
        for(int i=1;i<height.size()-1;i++)
        {
            int check=maxleft[i-1]<maxright[i+1]?maxleft[i-1]:maxright[i+1];
            int val=check-height[i];
            if(val>0)
            {
                ta+=val;
            }
            
        }
        return ta;
        
        
    }

int trap02(vector<int>& height) {
        stack<int> st;
        int tw=0;

        for(int i=0;i<height.size();i++)
        {
            while(st.size()>0 && height[st.top()]<=height[i])
            {
                int h=height[st.top()];
                st.pop();
                if(st.size()==0)
                {
                    break;
                }
                int w=i-st.top()-1;
                int min=height[i]<height[st.top()]?height[i]:height[st.top()];
                tw+=(min-h)*w;
            }
            st.push(i);
        }
        return tw;
    }

int trap03(vector<int>& height) {
        int lmax=0;
        int rmax=0;
       int left=0;
        int right=height.size()-1;
        int tw=0;
        while(left<right)
        {
            lmax=max(lmax,height[left]);
            rmax=max(rmax,height[right]);
            if(lmax<=rmax)
            {
                tw+=lmax-height[left];
                left++;
            }
            else
            {
                tw+=rmax-height[right];
                right--;
            }
        }
        return tw;
    }

// 456. 132 Pattern

 bool find132pattern(vector<int>& nums) 
 {
    if(nums.size()<3)
    {
        return false;
    }
    stack<int> st;
    int prev=INT_MIN;
    for(int i=nums.size()-1;i>=0;i--)
    {
        if(nums[i]<prev)
        {
            return true;
        }
        while(st.size()!=0 && st.top()<nums[i])
        {
            prev=st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
    
}

int main(int argc,char**argv)
{
    vector<int> v{1,2,-3,4,-5,6,10};
   vector<int> ans=ngor(v);
   for(int i:ans)
   {
       cout<<i<<" ";
   }
   cout<<endl;

}