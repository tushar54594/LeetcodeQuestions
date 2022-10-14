class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
         
        //base case
        for(int t=0; t<=amount; t++)
        {
            if(t%coins[0] == 0)
                dp[0][t] = t/coins[0];
            else
                dp[0][t] = 1e9;
        }
        
        for(int index=1; index<n; index++)
        {
            for(int t = 0; t<=amount; t++)
            {
                int notTake = 0 + dp[index-1][t];
                int take = 1e9;
                if(coins[index] <= t)
                    take = 1 + dp[index][t-coins[index]];
                
                dp[index][t] = min(notTake, take);
            }
        }
        if(dp[n-1][amount] == 1e9)
            return -1;
        
        return dp[n-1][amount];
    }
};