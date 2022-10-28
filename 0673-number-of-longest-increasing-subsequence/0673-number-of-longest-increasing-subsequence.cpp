class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); 
        vector<int> count(n, 1);
        
        int maxi = 1;
        for(int index=0; index<n; index++)
        {
            for(int prev=0; prev<index; prev++)
            {
                if(nums[prev] < nums[index] && 1 + dp[prev] > dp[index])
                {
                    dp[index] = 1 + dp[prev];
                    count[index] = count[prev]; //inherit
                }
                else if(nums[prev] < nums[index] && 1 + dp[prev] == dp[index])
                    count[index] += count[prev];  //increase the count
            }
            maxi = max(maxi, dp[index]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(dp[i] == maxi)
                ans += count[i];
        }
        
        return ans;
    }
};