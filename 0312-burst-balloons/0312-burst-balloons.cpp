class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>> &dp)
    {
        //base case
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = INT_MIN;
        for(int index=i; index<=j; index++)
        {
            int coins = nums[i-1]*nums[index]*nums[j+1] + f(i, index-1, nums, dp) + f(index+1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1); //insert 1 at end
        nums.insert(nums.begin(), 1); //insert 1 at beginning
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, nums, dp);
    } 
};