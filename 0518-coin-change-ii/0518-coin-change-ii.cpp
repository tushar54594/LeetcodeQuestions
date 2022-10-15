class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>> &dp)
    { 
        if(index == 0)
        {
            if(amount%coins[0] == 0)
                return 1;
            else
                return 0;
        }
        
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int notTake = solve(index-1, amount, coins, dp);
        int take = 0;
        if(coins[index] <= amount)
            take = solve(index, amount-coins[index], coins, dp); //it will be index not index-1
        
        return dp[index][amount] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        //base case
        for(int t = 0; t<=amount; t++)
        {
            if(t%coins[0] == 0)
                dp[0][t] = 1;
            else
                dp[0][t] = 0;
        }
        
        for(int index=1; index<n; index++)
        {
            for(int target=0; target<=amount; target++)
            {
                int notTake = dp[index-1][target];
                int take = 0;
                if(coins[index] <= target)
                    take = dp[index][target-coins[index]]; //it will be index not index-1

                dp[index][target] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};