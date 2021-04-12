#include<iostream>
#include<vector>
using namespace std;

int mazepath(int sr,int sc,int er,int ec,vector<vector<int>>&dp)
{
    
    if(sr==er && sc==ec)
    {
        return dp[er][ec]=1;
    }
    if(dp[sr][sc]!=0)
    {
        return dp[sr][sc];
    }
    int c=0;
    for(int i=1;i<=er;i++)
    { 
        if(sr+i<=er)
          c+=mazepath(sr+i,sc,er,ec,dp);
        
    }
    for(int i=1;i<=ec;i++)
    {
       if(sc+i<=ec)
          c+=mazepath(sr,sc+i,er,ec,dp);
    }
    for(int i=1;i<=er && i<=ec;i++)
    {
        if(sr+i<=er && sc+i<=ec)
          c+=mazepath(sr+i,sc+i,er,ec,dp);

    }
    return dp[sr][sc]=c;

}

void mazepathdp(int n,int m,vector<vector<int>>&dp)
{
    dp[n][m]=1;
    for(int i=n;i>=0;i--)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=1;k<=n;k++)
            {
                if(i+k<=n)
                {
                    dp[i][j]+=dp[i+k][j];
                }
            }
            for(int k=1;k<=m;k++)
            {
                if(j+k<=m)
                {
                    dp[i][j]+=dp[i][j+k];
                }
            }
            for(int k=1;k<=m && k<=n;k++)
            {
                if(i+k<=n && j+k<=m)
                {
                    dp[i][j]+=dp[i+k][j+k];
                }
            }

        }
    }
    cout<<dp[0][0]<<endl;

}

int targetreach(int si,int ei,vector<int>&dp1)
{
    if(si==ei)
    {
        return dp1[si]=1;
    }
    if(dp1[si]!=0)
    {
        return dp1[si];
    }
    int count=0;
    for(int i=1;i<=6;i++)
    {
        if(si+i<=ei)
        {
            count+=targetreach(si+i,ei,dp1);
        }
    }
    return dp1[si]=count;
}


void targetreachdpt(int ei,vector<int>&dp1)
{
    for(int i=ei;i>=0;i--)
    {
        if(i==ei)
        {
            dp1[ei]=1;
        }
        else
        {
            for(int j=1;j<=6;j++)
            {
                if(i+j<=ei)
                {
                    dp1[i]+=dp1[i+j];
                }
            }
        }
        
    }
    for(int i=0;i<=ei;i++)
    {
        cout<<dp1[i]<<" ";
    }
    cout<<endl;
}

int friendspair(int n,vector<int>&dp)
{
    if(n<=1)
    {
        return dp[n]=1;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int single=friendspair(n-1,dp);
    int paired=friendspair(n-2,dp)*(n-1);

    return dp[n]=(single+paired);

}

void friendspairDP(int n,vector<int>&dp)
{
    for(int i=0;i<=n;i++)
    {
        if(i==0 || i==1)
        {
            dp[i]=1;
        }
        else
        {
            dp[i]=dp[i-1]+(i-1)*dp[i-2];
        }
    }
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}


int minpathsum(int r,int c,vector<vector<int> >&grid)
{
    if(r==grid.size()-1 && c==grid[0].size()-1)
    {
        return grid[r][c];
    }
    int d=INT_MAX;
    if(c+1<=grid[0].size()-1)
    {
        d=minpathsum(r,c+1,grid);
    }
    int l=INT_MAX;
    if(r+1<=grid.size()-1)
    {
        l=minpathsum(r+1,c,grid);
    }
    int min=l<d?l:d;
    return min+grid[r][c];
}


int goldmine(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    if(c==grid[0].size()-1)
    {
        return dp[r][c]=grid[r][c];
    }
    if(dp[r][c]!=0)
    {
        return dp[r][c];
    }
    int maxcoins=0;
    int dir[3][2]={{-1,1},{0,1},{1,1}};
    for(int i=0;i<3;i++)
    {
        int x=r+dir[i][0];
        int y=c+dir[i][1];
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size())
        {
            int maxcoins=maxcoins>goldmine(x,y,grid,dp)?maxcoins:goldmine(x,y,grid,dp);
        }
    }
    return maxcoins;
}


//Substring and subsequence------------------------------------------

// bool ispalindromerec(int si,int ei,string s,vector<vector<int>>&dp)
// {
//     if(si>=ei)
//     {
//         return dp[si][ei]=1;
//     }
//     if(dp[si][ei]!=-1)
//     {
//         return dp[si][ei];
//     }
//     bool b=ispalindromerec(si+1,ei-1,s,dp);
//     if(b && s[si]==s[ei])
//     {
//         return dp[si][ei]=1;
//     }
//     return dp[si][ei]=0;
// }

void ispalindromesubstring(string s)
{
    int n=s.size();
    vector<vector<bool>> dp(n,vector<bool> (n,0));
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap==0)
            {
                dp[i][j]=true;
            }
            else if(gap==1 && s[i]==s[j])
            {
                dp[i][j]=true;
            }
            else
            {
                if(s[i]==s[j] && dp[i+1][j-1]==true)
                {
                    dp[i][j]=true;
                }
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}


void longestpalindromicsubstring(string s)
{
    int n=s.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap==0)
            {
                dp[i][j]=1;
            }
            else if(gap==1 && s[i]==s[j])
            {
                dp[i][j]=2;
            }
            else
            {
                if(s[i]==s[j] && dp[i+1][j-1]!=0)
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int longestpalindromicsubseq(int si,int ei,string s,vector<vector<int>>&dp)
{
    if(si>ei)
    {
        return dp[si][ei]= 0;
    }
    else if(si==ei)
    {
        return dp[si][ei]=1;
    }
    if(dp[si][ei]!=-1)
    {
        return dp[si][ei];
    }
    else
    {
        int len=0;
        if(s[si]==s[ei])
        {
            len=longestpalindromicsubseq(si+1,ei-1,s,dp)+2;
        }
        else
        {
            len=max(longestpalindromicsubseq(si,ei-1,s,dp),longestpalindromicsubseq(si+1,ei,s,dp));
        }
        return dp[si][ei]=len;
        
    }
    
    
}

void longestpalindromicsubseq(string str)
{
    vector<vector<int>>dp(str.size(),vector<int>(str.size(),0));
    for(int gap=0;gap<str.size();gap++)
    {
        for(int i=0,j=gap;j<str.size();i++,j++)
        {
            if(gap==0)
            {
               dp[i][j]=1;
            }
            else if(gap==1 && str[i]==str[j])
            {
                dp[i][j]=2;
            }
            else
            {
                if(str[i]==str[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j]=dp[i+1][j]>dp[i][j-1]?dp[i+1][j]:dp[i][j-1];
                }
                
            }
            
        }
    }

    for(int i=0;i<str.size();i++)
    {
        for(int j=0;j<str.size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


}

int distinctsubseq(int s1,int t1,string s,string t,vector<vector<int>>&dp)
{
    if(t1==t.size())
    {
        return dp[s1][t1]=1;
    }
    if(t.size()-t1>s.size()-s1)
    {
        return dp[s1][t1]=0;
    }
    if(dp[s1][t1]!=-1)
    {
        return dp[s1][t1];
    }
    if(s[s1]==t[t1])
    {
        return dp[s1][t1]=distinctsubseq(s1+1,t1+1,s,t,dp)+distinctsubseq(s1+1,t1,s,t,dp);
    }
    else
    {
        return dp[s1][t1]=distinctsubseq(s1+1,t1,s,t,dp);
    }
    

}

void countpalindromicsubseq(string s)
{
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
    for(int gap=0;gap<s.size();gap++)
    {
        for(int i=0,j=gap;j<s.size();i++,j++)
        {
            if(gap==0)
            {
                dp[i][j]=1;
            }
            else
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
                }
                else
                {
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                }
                
            }
            
        }
    }
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

void longestcommonsubstring(string s1,string s2)
{
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    int max=0;
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            max=max>dp[i][j]?max:dp[i][j];
        }
    }
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<max<<endl;
}

void longestcommonsubseq(string s1,string s2)
{
     vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
            }
            
            
        }
    }
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[s1.size()][s2.size()]<<endl;
}


//coin and target change-----------------------

void coinpermutationdp(vector<int> coins,int target)
{
     vector<int> dp(target+1,0);
     dp[0]=1;
     for(int i=1;i<dp.size();i++)
     {
         for(int coin:coins)
         {
             if(i-coin>=0)
             {
                 dp[i]+=dp[i-coin];
             }
         }
     }
     for(int val:dp)
     {
         cout<<val<<" ";
     }
     cout<<endl;
}

void coincombidp(vector<int> coins,int target)
{
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int coin:coins)
    {
        for(int i=coin;i<=target;i++)
        {
            dp[i]+=dp[i-coin];
        }
    }
    for(int val:dp)
     {
         cout<<val<<" ";
     }
     cout<<endl;
}


int coinsumcombi1(vector<int>&coins,int si,int tar,vector<vector<int>>&dp)
{
    if(si==coins.size() || tar==0)
    {
        if(tar==0)
        {
            return dp[si][tar]=1;
        }
        return dp[si][tar]=0;
    }
    int count=0;
    if(tar-coins[si]>=0)
    {
        count+=coinsumcombi1(coins,si+1,tar-coins[si],dp);
    }
    count+=coinsumcombi1(coins,si+1,tar,dp);
    return dp[si][tar]=count;

}

void reccount(vector<vector<int>>&dp,int idx,int tar,string ans,vector<int>&coins)
{
    if(idx==0 || tar==0)
    {
        if(tar==0)
        {
            cout<<ans<<endl;
        }
        return;
    }
    if(dp[idx-1][tar]>0)
    {
        reccount(dp,idx-1,tar,ans,coins);
    }
    if(dp[idx-1][tar-coins[idx-1]]>0)
    {
        reccount(dp,idx-1,tar-coins[idx-1],ans+to_string(coins[idx-1])+" ",coins);
    }
}

void coinsumcombi1dp(vector<int>&coins,int tar)
{
    vector<vector<int>>dp(coins.size()+1,vector<int>(tar+1,0));
    for(int i=0;i<=coins.size();i++)
    {
        for(int j=0;j<=tar;j++)
        {
            if(i==0 || j==0)
            {
                if(j==0)
                 dp[i][j]=1;
            }
            else
            {
                int val=j-coins[i-1]>=0?dp[i-1][j-coins[i-1]]:0;
                dp[i][j]=dp[i-1][j]+val;
            }
        }
    }
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    reccount(dp,coins.size(),tar,"",coins);
}


void knapsack01(vector<int>price,vector<int>weight,int cap)
{
    vector<vector<int>>dp(price.size()+1,vector<int>(cap+1,0));
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[0].size();j++)
        {
            int val=j-weight[i-1]>=0?dp[i-1][j-weight[i-1]]+price[i-1]:0;
            dp[i][j]=dp[i-1][j]>val?dp[i-1][j]:val;
        }
    }
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void knapsackunbounded(vector<int>&price,vector<int>&weight,int cap)
{
    vector<int> dp(cap+1,0);
    for(int j=0;j<weight.size();j++)
    {
         for(int i=weight[j];i<=cap;i++)
         {
             if(i-weight[j]==0)
             {
                 dp[i]=dp[i]>dp[i-weight[j]]+price[j]?dp[i]:dp[i-weight[j]]+price[j];
             }
             else if(dp[i-weight[j]]!=0)
             {
                  dp[i]=dp[i]>dp[i-weight[j]]+price[j]?dp[i]:dp[i-weight[j]]+price[j];
             }
         }
    }
    for(int val:dp)
    {
        cout<<val<<" ";
    }
    cout<<endl;

}

//increasing decreasing subseq.........................
//LIS LDS LBS LRBS longestincreasingmaxsumsubseq LC 354 min/del/forsortedarray countmaxLCS

void longestbitonicsubsequence()
 {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int>arr(n,0);
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        vector<int>lis(n,0);
        for(int p=0;p<n;p++)
        {
            lis[p]=1;
            for(int j=p-1;j>=0;j--)
            {
                if(arr[p]>arr[j])
                {
                    lis[p]=lis[p]>lis[j]+1?lis[p]:lis[j]+1;
                }
            }
        }
        vector<int>lds(n,0);
        for(int p=n-1;p>=0;p--)
        {
            lds[p]=1;
            for(int j=p+1;j<n;j++)
            {
                if(arr[p]>arr[j])
                {
                    lds[p]=lds[p]>lds[j]+1?lds[p]:lds[j]+1;
                }
            }
        }
        int ans=0;
        for(int j=0;j<n;j++)
        {
            if(lis[j]+lds[j]-1>ans)
            {
                ans=lis[j]+lds[j]-1;
            }
        }
        cout<<ans<<endl;
    }
	//code
	
}

//cuttype ===========================

int mcmrec(int si,int ei,vector<int>&arr,vector<vector<int>>&dp)
{
    if(si+1==ei)
    {
        return dp[si][ei]=0;
    }
    if(dp[si][ei]!=-1)
    {
        return dp[si][ei];
    }
    int ans=INT_MAX;
    for(int cut=si+1;cut<ei;cut++)
    {
        int leftcost=mcmrec(si,cut,arr,dp);
        int rightcost=mcmrec(cut,ei,arr,dp);
        if(ans>leftcost+arr[si]*arr[cut]*arr[ei]+rightcost)
        {
            ans=leftcost+arr[si]*arr[cut]*arr[ei]+rightcost;
        }
    }
    
    return dp[si][ei]=ans;
}

void mcmdp(vector<int> &arr)
{
    vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),INT_MAX));
    vector<vector<string>>sans(arr.size(),vector<string>(arr.size(),""));
    for(int gap=1;gap<arr.size();gap++)
    {
        for(int i=0,j=gap;j<arr.size();i++,j++)
        {
            if(gap==1)
            {
                sans[i][j]=char(i+'A');
                dp[i][j]=0;
            }
            else
            {
                for(int cut=i+1;cut<j;cut++)
                {
                    int lc=dp[i][cut];
                    int rc=dp[cut][j];
                    
                    if(lc+rc+arr[i]*arr[cut]*arr[j]<dp[i][j])
                    { 
                        dp[i][j]=lc+rc+arr[i]*arr[cut]*arr[j];
                        sans[i][j]="("+sans[i][cut]+sans[cut][j]+")";
                    }
                }
            }
            
        }
    }
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<"\t";
            cout<<sans[i][j]<<"\t";
        }
        cout<<endl;
    }
}


int optimalBSTrec(int si,int ei,vector<int>&keys,vector<int>&freq,vector<vector<int>>&dp)
{
    if(dp[si][ei]!=0)
    {
        return dp[si][ei];
    }
    int ans=INT_MAX;
    for(int i=si;i<=ei;i++)
    {
        int lc=i==si?0:optimalBSTrec(si,i-1,keys,freq,dp);
        int rc=i==ei?0:optimalBSTrec(i+1,ei,keys,freq,dp);
        int tempans=lc+rc+freq[ei+1]-freq[si];
        if(ans>tempans)
        {
            ans=tempans;
        }
    }
    return dp[si][ei]=ans;
}
  

void optimalBST(vector<int>&keys,vector<int>&freq)
{
    vector<vector<int>>dp(keys.size(),vector<int>(keys.size(),0));
    for(int gap=0;gap<dp.size();gap++)
    {
        for(int si=0,ei=gap;ei<dp.size();si++,ei++)
        {
            int ans=INT_MAX;
            for(int i=si;i<=ei;i++)
            {
                int lc=i==si?0:optimalBSTrec(si,i-1,keys,freq,dp);
                int rc=i==ei?0:optimalBSTrec(i+1,ei,keys,freq,dp);
                int tempans=lc+rc+freq[ei+1]-freq[si];
                if(ans>tempans)
                {
                    ans=tempans;
                }
            }
            dp[si][ei]=ans;

        }
    }

    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
}


//Extra Questions

//LC-91
 int mod=1e9+7;
int decodeWaysRec(int idx,string &s,vector<int>&dp)
{
    if(idx==s.size())
    {
        return dp[idx]=1;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    if(s[idx]=='0')
    {
        return dp[idx]=0;
    }
    int count=0;
    count+=decodeWaysRec(idx+1,s,dp);
    if(idx+1<s.size())
    {
        int num=(s[idx]-'0')*10+(s[idx+1]-'0');
        if(num<=26)
        {
           count+=decodeWaysRec(idx+2,s,dp);

        }
    }
    return dp[idx]=count;
}


//LC-639

long getans(int idx,string&s,vector<long>&dp)
    {
        if(idx==s.size())
        {
            return dp[idx]=1;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        if(s[idx]=='0')
        {
            return dp[idx]=0;
        }
        long count=0;
        if(s[idx]=='*')
        {
            count=(count%mod+(9*getans(idx+1,s,dp))%mod)%mod;
            if(idx+1<s.size())
            {
                if(s[idx+1]=='*')
                {
                     count=(count%mod+(15*(getans(idx+2,s,dp)%mod)%mod))%mod;
                }
                else if(s[idx+1]-'0'<=6)
                {
                    count=(count%mod+(2*(getans(idx+2,s,dp)%mod)%mod))%mod;
                }
                else if(s[idx+1]-'0'>6 && s[idx+1]-'0'<=9)
                {
                     count=(count%mod+(1*(getans(idx+2,s,dp)%mod)%mod))%mod;
                }
            }
        }
        else
        {
            count=(count%mod+(getans(idx+1,s,dp))%mod)%mod;
            if(idx+1<s.size())
            {
                if(s[idx+1]=='*')
                {
                    if(s[idx]=='1')
                      count=(count%mod+(9*(getans(idx+2,s,dp)%mod)%mod))%mod;
                    else if(s[idx]=='2')
                       count=(count%mod+(6*(getans(idx+2,s,dp)%mod)%mod))%mod;
                }
                else if(10*(s[idx]-'0')+(s[idx+1]-'0')<=26)
                {
                    count=(count%mod+(1*(getans(idx+2,s,dp)%mod)%mod))%mod;
                }
                
            }
            
        }
        return dp[idx]=count;
    }
    int numDecodings(string s) {
        vector<long>dp(s.size()+1,-1);
        return (int) getans(0,s,dp);
    }



//LC-940
int distinctSubseqII(string S) 
{
      
    vector<int>lastocc(26,0);
    vector<int>dp(S.size()+1,0);
    dp[0]=1;
    for(int i=0;i<S.size();i++)
    {
        dp[i+1]=(2*(dp[i]%mod))%mod;
        if(lastocc[S[i]-'a']!=0)
        {
            dp[i+1]=((dp[i+1]%mod)-(dp[lastocc[S[i]-'a']-1]%mod)+mod)%mod;
        }
        lastocc[S[i]-'a']=i+1;
    }
    
    cout<<endl;
        return dp[S.size()]-1;
        
}

//Count subsequences of type a^i b^j c^k 





int main(int argc,char**argv)
{
    // int n=2; int m=2;
    // vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    //cout<<mazepath(0,0,n,m,dp)<<endl;
    // int ei=10;
    // vector<int> dp1(ei+1,0);
    //cout<<targetreach(0,ei,dp1)<<endl;
    //targetreachdpt(ei,dp1);
    //int n=10;
    //vector<int> dp(n+1,0);
    //cout<<friendspair(n,dp)<<endl;
    //friendspairDP(n,dp);
    //string str="abafgababa";
    // vector<vector<int> >dp(str.size(),vector<int>(str.size(),-1));
    // cout<<longestpalindromicsubseq(0,str.size()-1,str,dp)<<endl;
    // for(int i=0;i<str.size();i++)
    // {
    //     for(int j=0;j<str.size();j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //longestpalindromicsubseq(str);

     //vector<vector<long>>dp(s.size()+1,vector<long>(t.size()+1,-1));
     //cout<< distinctsubseq(0,0,s,t,dp);
    
    //countpalindromicsubseq("aaaa");
    //longestcommonsubseq("aabacba","babaca");
    //vector<int> coins{2,3,5,7};
    //coincombidp(coins,10);
    //coinsumcombi1dp(coins,10);
    // vector<int>price{ 6, 100, 120 }; 
    // vector<int>weight{ 1, 2, 3 }; 
    // int cap = 6; 
    // knapsackunbounded(price,weight,cap);
    //  vector<int>arr{6,10,8,7,5,1};
    // vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
  
    // cout<<mcmrec(0,arr.size()-1,arr,dp)<<endl;
    // for(int i=0;i<dp.size();i++)
    // {
    //     for(int j=0;j<dp[0].size();j++)
    //     {
    //         cout<<dp[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    
    //cout<<endl<<endl<<endl;
    // mcmdp(arr);

    //  vector<int>keys {10, 12, 20};  
    //  vector<int>freq {34, 8, 50};  


    // vector<int>prefixsum(freq.size()+1,0);
    // for(int i=1;i<=freq.size();i++)
    // {
    //     prefixsum[i]=prefixsum[i-1]+freq[i-1];
    // }
    // vector<vector<int>>dp(keys.size(),vector<int>(keys.size(),0));

    // cout<<optimalBSTrec(0,keys.size()-1,keys,prefixsum,dp)<<endl;

    // for(int i=0;i<dp.size();i++)
    // {
    //     for(int j=0;j<dp[0].size();j++)
    //     {
    //         cout<<dp[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl<<endl<<endl;
    // optimalBST(keys,prefixsum);

    string s="226";
    vector<int> dp(s.size()+1,-1);

    //cout<<numDecodings_(s,0,dp)<<endl;
    cout<<decodeWaysRec(0,s,dp)<<endl;
    for(int j=0;j<dp.size();j++)
        {
            cout<<dp[j]<<"\t";
        }
        cout<<endl;

    
}