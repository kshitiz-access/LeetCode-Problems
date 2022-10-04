class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int k=nums.size()-1;
        int i=0;
        int j=nums.size()-1;
        while(i<=j)
        {
            int temp1=nums[i]*nums[i];
            int temp2=nums[j]*nums[j];
            if(temp1>=temp2){
                i++;
                res[k]=temp1;
                k--;
                
            }
            else
            {
                j--;
                res[k]=temp2;
                k--;
            }
        }
        return res;
    }
};