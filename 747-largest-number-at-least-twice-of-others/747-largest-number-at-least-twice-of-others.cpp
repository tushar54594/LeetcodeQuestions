class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = INT_MIN;
        int maxiIndex = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                maxiIndex = i;
            }
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(maxi < 2*nums[i] && nums[i] != maxi)
                return -1;
        }
        return maxiIndex;
    }
};