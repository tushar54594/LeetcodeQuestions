class Solution {
public:
    int solve(int index, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp)
    {
        int n = prices.size();
        //base case
        if(index == n || cap == 0)
            return 0;
        
        if(dp[index][buy][cap] != -1)
            return dp[index][buy][cap];
        
        int profit = 0;
        if(buy) 
        {
            int val1 = -prices[index] + solve(index+1, 0, cap, prices, dp); //buy(take)
            int val2 = 0 + solve(index+1, 1, cap, prices, dp); //notBuy(notTake)
            profit = max(val1, val2);
        }
        else //sell so +ve profit
        {
            int v1 = prices[index] + solve(index+1, 1, cap-1, prices, dp); //sell(transaction complete)
            int v2 = 0 + solve(index+1, 0, cap, prices, dp); //not sell
            profit = max(v1, v2);
        }
            
        return dp[index][buy][cap] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};