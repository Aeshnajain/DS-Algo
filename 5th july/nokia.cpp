#include<iostream>
#include<vector>
#include<string>

//nokia keypad problem

using namespace std;
string codes[10]={
    ".",
    "abc",
    "def",
    "ghi",
    "jklm",
    "no",
    "pqrs",
    "tu",
    "vwxy",
    "z"
};
vector<string> getkpc(string str)
{
    if(str.length()==0)
    {
         vector<string> bes;
        bes.push_back("");
        return bes;
    }
    int x=str[0];
    string ros=str.substr(1,str.length()-1);
    vector<string> rres=getkpc(ros);
    vector<string> mes;
    string base=codes[x-48];
    for(int i=0;i<rres.size();i++)
    {
        for(int j=0;j<base.length();j++)
        {
            string rstr=rres[i];
            mes.push_back(rstr+ base[j]);
        }

    }
    return mes;
}

// string nokia(string ques)
// {
//     if(ques.length()==0)
//     {
//         string bans="";
//         return bans;

//     }
//     char ch=ques[0];
//     string ros=ques.substr(1,ques.length());
//     string nans=nokia(ros);
//     string words=codes[ch-48];
//     string mans="";
//     for(int i=0;i<words.length();i++)
//     {
//          mans=mans+words[i]+nans;
//     }
//     return mans;
// }

void getans(int si,string &p,string myans,vector<string>&ans)
{
    if(si==p.length())
    {
        ans.push_back(myans);
    }
    int c=p[si]-'0';
    for(int i=0;i<codes[c].size();i++)
    {
        getans(si+1,p,myans+codes[c][i],ans);
    }

}

int main(int argc, char** argv)
{
  vector<string> words = getkpc("835");
   for(int i=0;i<words.size();i++)
   {
       cout<<words[i]<<" ";
   }
   cout<<endl;

   vector<string> ans;
   string p="835";
   getans(0,p,"",ans);
   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i]<<" ";
   }
   cout<<endl;

//   string ans=nokia("835");
//   for(int i=0;i<ans.length();i++)
//   {
//       cout<<ans[i];
//   }
}