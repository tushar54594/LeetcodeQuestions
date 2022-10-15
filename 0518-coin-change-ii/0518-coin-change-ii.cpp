class Solution {
public:  
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