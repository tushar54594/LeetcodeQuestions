class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        //we do n+1 since for index=n-1, we will have dp[n][] in notTake case
        
        for(int index=n-1; index>=0; index--)
        {
            for(int prev_index=index-1; prev_index>=-1; prev_index--)
            {
                int notTake = 0 + dp[index+1][prev_index+1];  //do second parameter +1 since coordinate shift
                int take = 0;
                if(prev_index == -1 || nums[index] > nums[prev_index])
                    take = 1 + dp[index+1][index+1];

                dp[index][prev_index+1] = max(notTake, take);
            }
        }
        return dp[0][-1+1];
    }
};