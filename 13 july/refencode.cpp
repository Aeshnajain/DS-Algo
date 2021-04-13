#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

void encodings(string& ques,string& asf)
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
           asf=asf+ans;
           encodings(roq,asf);
           asf.erase(asf.length()-1,1);
        
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
            asf=asf+ans;
           encodings(roq,asf);
           asf.erase(asf.length()-1,1);
           
        }
       int num=(ch-48)*10+(ch1-48);
       if(num>=10 && num<=26)
       {
           string roq=ques.substr(2,ques.length()-2);
           char ans=num+'a'-1;
        
            asf=asf+ans;
           encodings(roq,asf);
           asf.erase(asf.length()-1,1);
        
        }
    }

}

int main(int argv,char** argc)
{
    string code="1123";
    string asf="";
    encodings(code,asf);
    //stringstream sin(s);
    //int i=0;
    //sin>>i;
   // cout<<i<<endl;
}