class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            //if the amount is divible by coins[0], then this means that we can achieve are target and the                 number of coins required is amount/coins[0].
            //Eg. If the target is 12 and coins[0] = 4, then we see that amount is divible by coins[0] so                 answer will be 12 / 4 i.e. 3
            if((amount%coins[0]) == 0) 
                return amount/coins[0];
            else
                return 1e9;  //not possible so we do not take it
        }
        
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int notTake = 0 + solve(index-1, amount, coins, dp);
        int take = 1e9; //we want min so initialize it to 1e9
        if(coins[index] <= amount)
            take = 1 + solve(index, amount-coins[index], coins, dp);
        //we can take a coin any number of times so we call again index till coins[index] <= target
        
        return dp[index][amount] = min(notTake, take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, coins, dp);
        if(ans == 1e9)
            return -1;
            
        return ans;
    }
};