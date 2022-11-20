class Solution {
    vector<vector<int>> ans;
public:
    void subset(int idx,vector<int> &ds,vector<int> &a)
    {
        ans.push_back(ds);
        for(int i=idx;i<a.size();i++)
        {
            if(i>idx && a[i]==a[i-1]) continue;
            
            ds.push_back(a[i]);
            subset(i+1,ds,a);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subset(0,ds,nums);
        return ans;
    }
};