class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int midElem = nums[mid];
            if (midElem == target) {
                return mid;
            }
            
            int leftElem = nums[l];
            int rightElem = nums[r];
           
            if (leftElem == target) { 
                return l;
            } 
            else if (rightElem == target) {
                return r;
            }
            
            if (midElem < rightElem) { 
                if (midElem < target && target <= rightElem) { 
                    l = mid + 1;
                } else { 
                    r = mid - 1;
                }
                   
            } 
            else {
                if (midElem > target && target >= leftElem) { 
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        } 
        return -1;
    }
};