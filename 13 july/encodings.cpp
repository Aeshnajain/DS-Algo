#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

void encodings(string ques,string asf)
{
    if(ques.length()==0)
    {
        cout<<asf<<endl;
    }
    else if(ques.length()==1)
    {
        
        if(ques[0]!='0')
        {
           string roq=ques.substr(1,ques.length()-1);
           int num=ques[0]-48;
           char ans=num+'a'-1;
           
           encodings(roq,asf+ans);
        
        }
    }
    else
    {
       char ch=ques[0];
       char ch1=ques[1];
    
       if(ch!='0')
       {
           string roq=ques.substr(1,ques.length()-1);
           int num=ch-48;
           char ans=num+'a'-1;
           
           encodings(roq,asf+ans);
        
        
       }
       int num=(ch-48)*10+(ch1-48);
       if(num>=10 && num<=26)
       {
           string roq=ques.substr(2,ques.length()-2);
           char ans=num+'a'-1;
        
           encodings(roq,asf+ans);
           
       }
    }

}

void encode(int si,string code,string asf)
{
    if(si==code.length())
    {
        cout<<asf<<" ";
        return;
    }
    char c=code[si];
    if(c=='0')
    {
        return;
    }
    else
    {
        int val=c-'0';
        char ans=val+'a'-1;
        encode(si+1,code,asf+ans);
        if(si+1<code.length())
        {
            int numb=val*10+code[si+1]-'0';
            if(numb<26)
            {
                ans=numb+'a'-1;
                encode(si+2,code,asf+ans);

            }
            
        }
    }
    
}

int main(int argv,char** argc)
{
    string code="1023";
    string asf="";
    encodings(code,asf);
    encode(0,code,asf);
    //stringstream sin(s);
    //int i=0;
    //sin>>i;
   // cout<<i<<endl;
}