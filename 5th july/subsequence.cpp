#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> ss(string ques)
{
    if(ques.length()==0)
    {
       vector<string> bans;
       bans.push_back("");
       return bans;
    }
    char ch=ques[0];
    string rques=ques.substr(1,ques.length());
    vector<string> tans=ss(rques);
    vector<string> mans;
    for(int i=0;i<tans.size();i++)
    {
        mans.push_back(ch+tans[i]);
        mans.push_back('-'+tans[i]);
    }
    return mans;
}

int main(int argc,char** argv)
{
    vector<string> mans;
    mans=ss("abcd");
    for(int i=0;i<mans.size();i++)
    {
        cout<<mans[i]<<endl;
    }
}