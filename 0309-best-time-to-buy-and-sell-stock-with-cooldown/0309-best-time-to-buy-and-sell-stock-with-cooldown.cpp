class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, vector<vector<int>> &dp)
    {
        int n = prices.size();
        //base case
        if(index >= n)
            return 0;
        
        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit = 0;
        if(buy) 
        {
            int val1 = -prices[index] + solve(index+1, 0, prices, dp); //buy(take)
            int val2 = 0 + solve(index+1, 1, prices, dp); //notBuy(notTake)
            profit = max(val1, val2);
        }
        else //sell so +ve profit
        {
            int v1 = prices[index] + solve(index+2, 1, prices, dp); //sell
            int v2 = 0 + solve(index+1, 0, prices, dp); //not sell
            profit = max(v1, v2);
        }
            
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};