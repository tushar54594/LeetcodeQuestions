class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        //base case
        dp[n][0] = dp[n][1] = 0;
        
        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                int profit = 0;
                if(buy) 
                {
                    int val1 = -prices[index] + dp[index+1][0]; //buy(take)
                    int val2 = 0 + dp[index+1][1]; //notBuy(notTake)
                    profit = max(val1, val2);
                }
                else //sell so +ve profit
                {
                    int v1 = prices[index] + dp[index+1][1] - fee; //sell
                    int v2 = 0 + dp[index+1][0]; //not sell
                    profit = max(v1, v2);
                }

                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};