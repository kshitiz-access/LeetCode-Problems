class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        int res=-1;
        while(low<=high)
        {
            int mid = low+(high - low)/2;
            if(nums[mid] == target)
            {
                res=mid;
                break;
            }
            else if(nums[mid] > target)
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                res=mid+1;
                low=mid+1;
            }
        }
        return res;
    }
};