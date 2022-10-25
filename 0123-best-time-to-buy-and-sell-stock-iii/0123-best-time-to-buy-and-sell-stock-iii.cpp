class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
   
        //no need of base case as we are already initializing it to 0
        
        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int cap=1; cap<=2; cap++) //since cap==0 will be 0(base case)
                {
                    int profit = 0;
                    if(buy) 
                    {
                        int val1 = -prices[index] + dp[index+1][0][cap]; //buy(take)
                        int val2 = 0 + dp[index+1][1][cap]; //notBuy(notTake)
                        profit = max(val1, val2);
                    }
                    else //sell so +ve profit
                    {
                        int v1 = prices[index] + dp[index+1][1][cap-1]; //sell(transaction complete)
                        int v2 = 0 + dp[index+1][0][cap]; //not sell
                        profit = max(v1, v2);
                    }

                    dp[index][buy][cap] = profit;
                }
            }
        }
        
        return dp[0][1][2];
    }
};