class Solution {
public:
    void solve(int idx,string tiles,int &check,int &ans,string t)
    {
        if(idx==tiles.size())
        {
            return;
        }
        int safecheck=0;
        for(int i=0;i<tiles.size();i++)
        {
            int idx=tiles[i]-'A';
            int smask=1<<idx;
            int mask=1<<i;
            if((mask&check)==0 && (smask&safecheck)==0)
            {
                check^=mask;
                safecheck^=smask;
                 ans=ans+1;
                cout<<t<<endl;
                solve(i+1,tiles,check,ans,t+tiles[i]);
               
                safecheck^=smask;
                check^=mask;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int ans=0;
        int check=0;
        solve(0,tiles,check,ans,"");
        return ans;
    }
};