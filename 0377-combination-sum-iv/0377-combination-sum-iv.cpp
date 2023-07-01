class Solution {
public:
    int solve(vector<int> &arr, int target, vector<int> &dp)
    {
        if(target < 0) return 0;
        if(target == 0) return 1;
        
        if(dp[target] != -1) return dp[target];
        
        int ans = 0;
        //har target pe har no try karna hai
        for(int i=0; i<arr.size(); i++){
            ans += solve(arr, target - arr[i], dp);
        }
        
        return dp[target] = ans;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }
};