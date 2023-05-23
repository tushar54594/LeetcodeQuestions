class Solution {
public:
    int solve(int i, vector<int> nums, vector<int> &dp)
    {
        if(i == 0) return nums[0];
        if(i < 0) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int pick = nums[i] + solve(i-2, nums, dp);
        int notPick = 0 + solve(i-1, nums, dp);
        
        return dp[i] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++)
        { 
            if(i != 0) temp2.push_back(nums[i]);
            if(i != n-1) temp1.push_back(nums[i]);
        }
        
        vector<int> dp1(n, -1);
        int ans1 = solve(n-2, temp1, dp1);
        vector<int> dp2(n, -1);
        int ans2 = solve(n-2, temp2, dp2);
        
        return max(ans1, ans2);
    }
};

/*
Treat it as 2 house robber problmes
case 1 - take 1st house and not last
case 2 - take last house and not 1st
*/