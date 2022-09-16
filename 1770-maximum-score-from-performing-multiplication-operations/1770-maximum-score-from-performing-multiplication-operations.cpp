class Solution {
public:
    int f(vector<int>& nums,vector<int>& multipliers,int n,int m,int i,int j,int idx,vector<vector<int>>&dp)
    {
        if(idx== m)
        {
            return 0;
        }
        if(dp[i][idx] != INT_MIN) return dp[i][idx];
        //ith nums
        long long way1=nums[i]*multipliers[idx] + f(nums,multipliers,n,m,i+1,j,idx+1,dp);
        long long way2=nums[j]*multipliers[idx] + f(nums,multipliers,n,m,i,j-1,idx+1,dp);
        
        return dp[i][idx] = max(way1,way2);
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n =nums.size();
        int m=multipliers.size();
        vector<vector<int>> dp(m+1,vector<int> (m+1,INT_MIN));
        return f(nums,multipliers,n,m,0,n-1,0,dp);
        
    }
};