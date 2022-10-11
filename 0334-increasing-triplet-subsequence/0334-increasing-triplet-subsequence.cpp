class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x,y,z;
        bool j,k,l;
        j=k=l=0;
        x=y=z=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(x>nums[i]){ x=nums[i]; j=1;}
            if(nums[i]>x && nums[i]<y) {y=nums[i]; k=1;}
            if(nums[i]>y && nums[i]<=z) {z=nums[i]; l=1;}
            if(l&&j&&k) return 1;
        }
        return 0;
    }
};