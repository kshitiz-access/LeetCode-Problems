class Solution {
public:
    int minInsertions(string s) {
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // return f(n,m,text1,text2,dp);
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j]=  1+dp[i-1][j-1];
                else
                {
                    dp[i][j]= max(dp[i-1][j] ,dp[i][j-1]);
                }
            }
        }
        int p=dp[n][m];
        return n-p;
    }
};