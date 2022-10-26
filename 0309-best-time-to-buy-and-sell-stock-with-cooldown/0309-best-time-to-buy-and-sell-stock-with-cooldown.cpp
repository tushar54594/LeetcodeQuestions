class Solution {
public:  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); //since we have index+2
        
        //base case
        dp[n][0] = dp[n][1] = 0;
        
        for(int index=n-1; index>=0; index--)
        {
            int val1 = -prices[index] + dp[index+1][0]; //buy(take)
            int val2 = 0 + dp[index+1][1]; //notBuy(notTake)
            dp[index][1]= max(val1, val2);
                
                
            int v1 = prices[index] + dp[index+2][1]; //sell
            int v2 = 0 + dp[index+1][0]; //not sell
            dp[index][0] = max(v1, v2);
        }
        return dp[0][1];
    }
};