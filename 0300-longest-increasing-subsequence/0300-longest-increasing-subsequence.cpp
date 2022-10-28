class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); //initialize the dp array to 1
        int maxi = 1;
        
        for(int index=1; index<n; index++)
        {
            for(int prev=0; prev<index; prev++)
            {
                if(nums[prev] < nums[index])
                    dp[index] = max(1 + dp[prev], dp[index]);
            }
            maxi = max(maxi, dp[index]);
        }
        return maxi;
    }
};