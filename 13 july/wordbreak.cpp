#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

void wordbreak(string sent,string asf,unordered_set<string>& dictionary)
{
    if(sent.length()==0)
    {
        cout<<asf<<endl;
        return;
    }
    for(int i=1;i<=sent.length();i++)
    {
        string prefix=sent.substr(0,i);
        if(dictionary.count(prefix)==1)
        {
            string rsen=sent.substr(i,sent.length()-prefix.length());
            wordbreak(rsen,asf+prefix+"-",dictionary);
        }
    }
}

int main(int argc,char** argv)
{
    unordered_set<string> dictionary;
    dictionary.insert("man");
    dictionary.insert("go");
    dictionary.insert("ice");
    dictionary.insert("cream");
    dictionary.insert("sam");
    dictionary.insert("sung");
    dictionary.insert("mango");
    dictionary.insert("icecream");
    dictionary.insert("samsung");
    wordbreak("mangoicecreamsamsung","",dictionary);
}