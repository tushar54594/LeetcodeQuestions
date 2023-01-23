class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int currSum = 0;
        
        // stores endpoints of maximum sum subarray found so far
        int start = 0, end = 0;
        // stores starting index of a positive-sum sequence
        int beg = 0;
        
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