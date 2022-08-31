class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int currSum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            currSum += nums[i];
            maxi = max(maxi, currSum);
            
            if(currSum < 0)
                currSum = 0;
        }
        return maxi;
    }
};