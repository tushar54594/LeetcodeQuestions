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
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int i=n; i>=1; i--)
        {
            for(int j=i; j<=n; j++)
            {
                int maxi = INT_MIN;
                for(int index=i; index<=j; index++)
                {
                    int coins = nums[i-1]*nums[index]*nums[j+1] + dp[i][index-1] + dp[index+1][j];
                    maxi = max(maxi, coins);
                }

                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    } 
};