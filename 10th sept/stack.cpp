#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

bool hasduplicatebrack(string& eq)
{
    stack<char> s;

    for(int i=0;i<eq.size();i++)
    {
        if(eq[i]==')')
        {
            if(s.top()=='(')
            {
                return true;
            }
            else 
            {
                while(s.top()!='(')
                {
                    s.pop();
                }
                s.pop();
            }


        }
        else 
        {
            s.push(eq[i]);
        }
    }

    return false;
}

// bool isbalancedbrack(string& eq)
// {
//     stack<char> s;
//     for(int i=0;i<s.size();i++)
//     {
//         if(eq[i]==')')
//         {
//             while(eq[i]!='(')
//             {
//                s.pop();
//                if(s.top()=='{' || s.top()=='[')
//                {
//                    return false;
//                }
//                if(s.size()==0)
//                {
//                    return false;
//                }
//             }
//             s.pop();

//         }
//         if(eq[i]=='}')
//         {
//             while(eq[i]!='{')
//             {
//                s.pop();
//                if(s.top()=='(' || s.top()=='[')
//                {
//                    return false;
//                }
//                if(s.size()==0)
//                {
//                    return false;
//                }
//             }
//             s.pop();

//         }
//         if(eq[i]==']')
//         {
//             while(eq[i]!='[')
//             {
//                s.pop();
//                if(s.top()=='{' || s.top()=='(')
//                {
//                    return false;
//                }
//                if(s.size()==0)
//                {
//                    return false;
//                }
//             }
//             s.pop();

//         }
//         else 
//         {
//             s.push(eq[i]);
//         }
        
//     }
//     return true;
// }

bool isbalancedbrack(string& eq)
{
    stack<char> s;
    for(int i=0;i<eq.size();i++)
    {
        if(eq[i]=='(' || eq[i]=='[' || eq[i]=='{')
        {
            s.push(eq[i]);
        }
        else if(eq[i]==')')
        {
            if(s.size()==0 && s.top()!='(')
            {
                return false;
            }
            else
            {
                s.pop();
            }
            
        }
        else if(eq[i]=='}')
        {
            if(s.size()==0 && s.top()!='{')
            {
                return false;
            }
            else
            {
                s.pop();
            }
            
        }
        else if(eq[i]==']')
        {
            if(s.size()==0 && s.top()!='[')
            {
                return false;
            }
            else
            {
                s.pop();
            }
            
        }
    }
    if(s.size()>0)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

vector<int> nge1(vector<int> arr)
{
    stack<int> st;
    vector<int> res(arr.size());

    for(int i=0;i<arr.size();i++)
    {
        while(st.size()>0 && arr[st.top()]<arr[i])
        {
            res[st.top()]=arr[i];
            st.pop();
        }
            st.push(i);
        
        
    }
    while(st.size()>0)
    {
        res[st.top()]=-1;
        st.pop();
    }
    return res;

}

vector<int> nge2(vector<int> arr)
{
    stack<int> st;
    vector<int> res(arr.size());

    res[arr.size()-1]=-1;
    st.push(arr[arr.size()-1]);

    for(int i=arr.size()-2;i>=0;i--)
    {
        while(st.size()>0 && st.top()<arr[i])
        {
            st.pop();
        }
        res[i]=st.size()==0?-1:st.top();
        st.push(arr[i]);
    }
    return res;

}

vector<int> nser(vector<int>& arr)
{
    stack<int> st;
    vector<int> res(arr.size());

    res[arr.size()-1]=arr.size();
    st.push(arr.size()-1);

    for(int i=arr.size()-2;i>=0;i--)
    {
        while(st.size()>0 && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        res[i]=st.size()==0?-1:st.top();
        st.push(i);
    }
    return res;

}

vector<int> nsel(vector<int>& arr)
{
    stack<int> st;
    vector<int> res(arr.size());

    res[0]=-1;
    st.push(0);

    for(int i=1;i<arr.size();i++)
    {
        while(st.size()>0 && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        res[i]=st.size()==0?-1:st.top();
        st.push(i);
    }
    return res;

}

int areaoflarghisto(vector<int>& arr)
{
    vector<int> nseor=nser(arr);
    vector<int> nseol=nsel(arr);
    int max=0;

    for(int i=0;i<arr.size();i++)
    {
        int area=(nseor[i]-nseol[i]-1)*arr[i];
        if(area>max)
        {
            max=area;
        }

    }
    return max; 
}

vector<int> maxinwindow(vector<int> arr,int k)
{
    stack<int> st;
    vector<int> gne(arr.size());

    for(int i=0;i<arr.size();i++)
    {
        while(st.size()>0 && arr[st.top()]<arr[i])
        {
            gne[st.top()]=i;
            st.pop();
        }
            st.push(i);
        
        
    }
    while(st.size()>0)
    {
        gne[st.top()]=arr.size();
        st.pop();
    }
    
    int i=0;
    int j=0;

    vector<int> res(arr.size()-k+1);
    while(i<res.size())
    {
        if(i>j)
        {
            j=i;
        }
        while(gne[j]<k+i)
        {
            j=gne[j];
        }
        res[i]=arr[j];
        i++;

    }
    return res;




}

void ddid(string s)
{
    stack<int> st;
    st.push(1);
    int c=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='i')
        {
            while(st.size()>0)
            {
                
                cout<<st.top()<<" ";
                st.pop();
            }
            c++;
            st.push(c);
        
           // cout<<endl;

        }
        else 
        {
            c++;
            st.push(c);
        }
    }
    while(st.size()>0)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;


}
int getprior(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
         return 1;
        case '*':
        case '/':
        case '%':
         return 2;
        case '^':
         return 3;

    }
    return 0;
}

int getvalue(int v1,int v2,char ch)
{
    switch(ch)
    {
        case '+':
         return v1+v2;
         break;
        case '-':
         return v1-v2;
         break;
        case '*':
         return v1*v2;
         break;
        case '/':
         return v1/v2;
         break;
        case '%':
         return v1%v2;
         break;
        case '^':
         return pow(v1,v2);
         break;
        default:
         break;

    }
    return 0;

}

int infix123(string exp)
{
    stack<int> vs;
    stack<char> os;
    stack<string> post;
    stack<string> pre;
    for(int i=0;i<exp.size();i++)
    {
        char ch=exp[i];
        if(ch>='0' && ch<='9')
        {
            vs.push(ch-48);
            pre.push(to_string(ch-48));
            post.push(to_string(ch-48));

        }
        else if(ch=='(')
        {
            os.push(ch);
        }
        else if (ch==')')
        {
            while(os.top()!='(')
            {
                int v2=vs.top(); vs.pop();
                int v1=vs.top(); vs.pop();
                char op=os.top(); os.pop();
                int rem=getvalue(v1,v2,op);
                vs.push(rem);

                string pre2=pre.top(); pre.pop();
                string pre1=pre.top(); pre.pop();
                pre.push(op+pre1+pre2);

                string post2=post.top(); post.pop();
                string post1=post.top(); post.pop();
                post.push(post1+post2+op);
            }
            os.pop();
        }
        else 
        {
            while(os.size()>0 && os.top()!='(' && getprior(os.top())>=getprior(ch))
            {
                int v2=vs.top(); vs.pop();
                int v1=vs.top(); vs.pop();
                char op=os.top(); os.pop();
                int rem=getvalue(v1,v2,op);
                vs.push(rem);

                string pre2=pre.top(); pre.pop();
                string pre1=pre.top(); pre.pop();
                pre.push(op+pre1+pre2);

                string post2=post.top(); post.pop();
                string post1=post.top(); post.pop();
                post.push(post1+post2+op);
            }
             os.push(ch);

        }
        
    }
    while(os.size()>0)
    {
        int v2=vs.top(); vs.pop();
        int v1=vs.top(); vs.pop();
        char op=os.top(); os.pop();
        int rem=getvalue(v1,v2,op);
        vs.push(rem);

        string pre2=pre.top(); pre.pop();
        string pre1=pre.top(); pre.pop();
        pre.push(op+pre1+pre2);

        string post2=post.top(); post.pop();
        string post1=post.top(); post.pop();
        post.push(post1+post2+op);

    }

    cout<<"pre"<<" "<<pre.top()<<endl;
    cout<<"post"<<" "<<post.top()<<endl;

    return vs.top();
}

int postfix123(string exp)
{
    stack<int> val;
    stack<string> in;
    stack<string> pre;

    for(int i=0;i<exp.length();i++)
    {
        char ch=exp[i];
        if(ch>='0' && ch<='9')
        {
            val.push(ch-48);
            in.push(to_string(ch-48));
            pre.push(to_string(ch-48));
        }
        else
        {
            int v2=val.top(); val.pop();
            int v1=val.top(); val.pop();
            int res=getvalue(v1,v2,ch);
            val.push(res);

            string prev2=pre.top(); pre.pop();
            string prev1=pre.top(); pre.pop();
            pre.push(ch+prev1+prev2);

            string inv2=in.top(); in.pop();
            string inv1=in.top(); in.pop();
            in.push("("+inv1+ch+inv2+")");

        }
        
    }

    cout<<"pre"<<" "<<pre.top()<<endl;
    cout<<"in"<<" "<<in.top()<<endl;

    return val.top();


}

class interval
{
    public:
        int start;
        int end;

        interval(int start,int end)
        {
            this->start=start;
            this->end=end;
        }

        bool operator<(const interval& other) const
        {
            return this->start<other.start;

        }

};

void mergeoverlappingintervals(vector<int>& starts,vector<int>& ends)
{
    vector<interval> intvs;

    for(int i=0;i<starts.size();i++)
    {
        interval e(starts[i],ends[i]);
        intvs.push_back(e);
    }

    sort(intvs.begin(),intvs.end());
    stack<interval> st;
    
    st.push(intvs[0]);
    
    for(int i=1;i<intvs.size();i++)
    {
        if(st.top().end>intvs[i].start)
        {
            st.top().end=st.top().end>intvs[i].end?st.top().end:intvs[i].end;
        
        }
        else
        {
            st.push(intvs[i]);
        }
        
        
    }
    while(st.size()>0)
    {
        interval e=st.top();
        cout<<e.start<<" "<<e.end<<endl;
        st.pop();
    }
}
int main(int argc,char** argv)
{
    //string s="(a+((b+c)))";
    //cout<<hasduplicatebrack(s)<<endl;
    //string s="[a+{b+(d+e}]";
    //cout<<isbalancedbrack(s)<<endl;
    vector<int> arr {6,2,5,4,5,1,6};
    //int m=nge2(arr);
    //cout<<areaoflarghisto(arr);
    // for(int i=0;i<area.size();i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    //cout<<endl;
    int k=5;
    //vector<int> res=maxinwindow(arr,k);
    //cout<<areaoflarghisto(arr);
    // for(int i=0;i<res.size();i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;

    //ddid("ddiiddii");

    int i=infix123("8+3^(4/(3-2))");
    cout<<i<<endl;
    cout<<postfix123("83432-/^+")<<endl;

    vector<int> start {1,6,5,2};
    vector<int> end {3,8,7,4};

    mergeoverlappingintervals(start,end);
   

}