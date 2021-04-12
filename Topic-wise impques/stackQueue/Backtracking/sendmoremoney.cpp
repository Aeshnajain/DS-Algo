#include<iostream>
#include<string>
#include<vector>

using namespace std;

string s1="send";
string s2="more";
string s3="money";

int getsol(string &u,vector<int>&st,int idx,int ch)
{
    if(idx==u.size())
    {
        int num1=0;
        for(int i=0;i<s1.size();i++)
        {
           num1=num1*10+st[s1[i]-'a']; 
        }
        int num2=0;
        for(int i=0;i<s2.size();i++)
        {
           num2=num2*10+st[s2[i]-'a']; 
        }
        int num3=0;
        for(int i=0;i<s3.size();i++)
        {
           num3=num3*10+st[s3[i]-'a']; 
        }
        if(num1+num2==num3)
        {
            cout<<num1<<" "<<num2<<" "<<num3<<endl;
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    int count=0;
    for(int i=0;i<=9;i++)
    {
        int mask=1<<i;
        if((mask&ch)==0)
        {
            ch^=mask;
            st[u[idx]-'a']=i;
            count+=getsol(u,st,idx+1,ch);
            st[u[idx]-'a']=-1;
            ch^=mask;

        }
    }
    return count;
}

int main(int argc,char**argv)
{
    int check=0;
    string unique="";
    for(int i=0;i<s1.size();i++)
    {
        int mask=1<<(s1[i]-'a');
        if((check&mask)==0)
        {
           check^=mask;
           unique+=s1[i];
        }
    }
    for(int i=0;i<s2.size();i++)
    {
        int mask=1<<(s2[i]-'a');
        if((check&mask)==0)
        {
           check^=mask;
           unique+=s2[i];
        }
    }
    for(int i=0;i<s3.size();i++)
    {
        int mask=1<<(s3[i]-'a');
        if((check&mask)==0)
        {
           check^=mask;
           unique+=s3[i];
        }
    }
    vector<int>st(26,-1);
    cout<<getsol(unique,st,0,0)<<endl;


    
    
}