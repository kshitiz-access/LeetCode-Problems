class Solution {
public:
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i==0) return j;
        if(j==0) return i;
        
        if(dp[i][j] !=-1) return dp[i][j];
        
        if(s1[i-1]== s2[j-1])
             return dp[i][j] = f(i-1,j-1,s1,s2,dp);
        else
        {
            return dp[i][j] = min( 1+ f(i-1,j-1,s1,s2,dp),min(1 + f(i-1,j,s1,s2,dp),1+f(i,j-1,s1,s2,dp)));
        }
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // return f(n,m,s1,s2,dp);
        
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]== s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = min(1+ dp[i-1][j-1],min(1 + dp[i-1][j],1+dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};