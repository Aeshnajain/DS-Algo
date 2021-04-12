#include<iostream>
#include<vector>
using namespace std;

vector<string> matrix; 
vector<string> words; 

bool canplaceH(int x,int y,string word)
{
    if(y-1>=0 && matrix[x][y-1]!='*')
    {
        return false;
    }
    if(y+word.length()<matrix[0].length() && matrix[x][y+word.length()]!='*')
    {
        return false;
    }
    for(int i=0;i<word.length();i++)
    {
         if(y+i>matrix[0].size())
         {
             return false;
         }
        else if( matrix[x][y+i]!='#' && matrix[x][y+i]!=word[i])
        {
            return false;
        }
    }
    return true;

}

vector<bool> placeH(int x,int y,string word)
{
    vector<bool> loc(word.length(),false);
    for(int i=0;i<word.length();i++)
    {
        if(matrix[x][y+i]=='#')
        {
            loc[i]=true;
            matrix[x][y+i]=word[i];
        }
    }
    return loc;
}

void unplaceH(int x,int y,string word,vector<bool> loc)
{
    for(int i=0;i<word.length();i++)
    {
        if(loc[i]==true)
        {
            matrix[x][y+i]='#';
        }
    }

}

bool canplaceV(int x,int y,string word)
{
    if(x-1>=0 && matrix[x-1][y]!='*')
    {
        return false;
    }
    if(x+word.length()<matrix.size() && matrix[x+word.length()][y]!='*')
    {
        return false;
    }
    for(int i=0;i<word.length();i++)
    {
         if(x+i>matrix.size())
         {
             return false;
         }
        else if( matrix[x+i][y]!='#' && matrix[x+i][y]!=word[i])
        {
            return false;
        }
    }
    return true;

}

vector<bool> placeV(int x,int y,string word)
{
    vector<bool> loc(word.length(),false);
    for(int i=0;i<word.length();i++)
    {
        if(matrix[x+i][y]=='#')
        {
            loc[i]=true;
            matrix[x+i][y]=word[i];
        }
    }
    return loc;
}

void unplaceV(int x,int y,string word,vector<bool> loc)
{
    for(int i=0;i<word.length();i++)
    {
        if(loc[i]==true)
        {
            matrix[x+i][y]='#';
        }
    }

}

int solve(int idx)
{
    if(idx==words.size())
    {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }
    int count=0;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
             if(matrix[i][j]=='#' || matrix[i][j]==words[idx][0])
             {
                 if(canplaceH(i,j,words[idx]))
                 {
                     vector<bool> loc=placeH(i,j,words[idx]);
                     count+=solve(idx+1);
                     unplaceH(i,j,words[idx],loc);
                 }
                 if(canplaceV(i,j,words[idx]))
                 {
                     vector<bool> loc=placeV(i,j,words[idx]);
                     count+=solve(idx+1);
                     unplaceV(i,j,words[idx],loc);
                 }
             }
        }
    }
    return count;
}
  
int main(int argc,char**argv)
{
    matrix.push_back("*#********"); 
    matrix.push_back("*#********"); 
    matrix.push_back("*#****#***"); 
    matrix.push_back("*##***##**"); 
    matrix.push_back("*#****#***"); 
    matrix.push_back("*#****#***"); 
    matrix.push_back("*#****#***"); 
    matrix.push_back("*#*######*"); 
    matrix.push_back("*##*******"); 
    matrix.push_back("***#######"); 
  
    
    words.push_back("PUNJAB"); 
    words.push_back("JHARKHAND"); 
    words.push_back("MIZORAM"); 
    words.push_back("MUMBAI");

    cout<<solve(0)<<endl;

}