class Solution {
public:
    int f(int i,int t,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(t%coins[0] == 0) return 1;
            return 0;
        }
        if(dp[i][t]!=-1)
            return dp[i][t];
        int nottake=f(i-1,t,coins,dp);
        int take=0;
        if(coins[i]<=t)
        {
            take=f(i,t-coins[i],coins,dp);
        }
        return dp[i][t]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};