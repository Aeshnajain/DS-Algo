#include<iostream>
#include<vector>
using namespace std;
string s1="send";
string s2="more";
string s3="money";
int check=0;
vector<int> assignno(26,0);

int tonum(string w)
{
    int num=0;
    for(int i=0;i<w.length();i++)
    { 
        if(i==0 && assignno[w[i]-'a']==0)
        {
            return 0;
        }
        num=num*10+assignno[w[i]-'a'];
    }
    return num;

}

int solve(string str,int idx)
{
    if(idx==str.length())
    {
        int num1=tonum(s1);
        int num2=tonum(s2);
        int num3=tonum(s3);
        if(num1!=0 && num2!=0 && num3!=0 && num1+num2==num3)
        { 
            for(int i=0;i<str.length();i++)
            {
                
                cout<<str[i]<<" "<<assignno[str[i]-'a']<<endl;
                
            }
            return 1;
        }
        return 0;
    }
    int count=0;
    for(int i=0;i<=9;i++)
    { 
        int mask=1<<i;
        if((mask&check)==0)
        {
            check^=mask;
            assignno[str[idx]-'a']=i;
            count+=solve(str,idx+1);
            check^=mask;
            assignno[str[idx]-'a']=0;
        }

    }
    return count;

}

int main(int argc,char**argv)
{
    string str=s1+s2+s3;
    vector<int> freq(26,0);
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-'a']++;
    }
    str="";
    for(int i=0;i<26;i++)
    {
        if(freq[i]>0)
        {
            str+=(char)(i+'a');
        }
    }
    int ans=solve(str,0);
    cout<<ans<<endl;

}
