class Solution {
public:
    vector<int>org;
    int n;
    Solution(vector<int>& nums) {
        org = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        vector<int> arr = org;
        int sz = n;
        for(int i=n-1;i>-1;i--)
        {
            int ind = rand()%sz--;
            swap(arr[ind],arr[i]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */