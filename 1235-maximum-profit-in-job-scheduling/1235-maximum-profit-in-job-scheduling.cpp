class Solution {
public:
    int f(int i,vector<vector<int>>& job,vector<int>& st,int n,vector<int>& dp){
		if(i>=n) return 0;
		if(dp[i]!=-1) return dp[i];
		int ind=lower_bound(st.begin(),st.end(),job[i][1])-st.begin();
		int pick=job[i][2]+f(ind,job,st,n,dp);
		int notpick=f(i+1,job,st,n,dp);
		return dp[i]=max(pick,notpick);
	}

	int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pro){
		int n=st.size();
		vector<vector<int>> job;
		vector<int> dp(n+1,0);
		for(int i=0;i<n;i++) job.push_back({st[i],et[i],pro[i]});  
		sort(job.begin(),job.end());
		sort(st.begin(),st.end());
		for(int i=n-1;i>=0;i--){
			int ind=lower_bound(st.begin(),st.end(),job[i][1])-st.begin();
			int pick=job[i][2]+dp[ind];
			int notpick=dp[i+1];
			dp[i]=max(pick,notpick);
		}
		return dp[0];
		// return f(0,job,st,n,dp);
	}
};