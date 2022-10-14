class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane's Algorithm
        int n=nums.size();
        int sum=0;
        int maxi=nums[0];
        int i=0;
        while(i<n)
        {
            sum+=nums[i];
            if(sum>maxi) maxi=sum;
            if(sum <0)
            {
                sum=0;
            }
           
            i++;
        }
        return maxi;
        
    }
};