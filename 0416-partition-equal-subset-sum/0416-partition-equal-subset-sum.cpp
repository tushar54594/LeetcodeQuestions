class Solution {
public:
    bool solve(int index, int target, vector<int>& nums, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;
        if(index == 0)
            return nums[0] == target;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        bool notTake = solve(index-1, target, nums, dp);
        bool take = false;
        if(nums[index] <= target)
            take = solve(index-1, target-nums[index], nums, dp);
        
        return dp[index][target] = take || notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        //calculate the total sum
        int s = 0;
        for(int i=0; i<n; i++)
            s += nums[i];
        
        //if total sum is odd return false
        if(s%2 != 0)
            return false;
        
        int target = s/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(n-1, target, nums, dp);
    }
};