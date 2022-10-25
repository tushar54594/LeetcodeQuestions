class Solution {
public:
    int solve(int index, int trans, vector<int>& prices, vector<vector<int>> &dp)
    {
        int n = prices.size();
        //base case
        if(index == n || trans == 4)   //at most two transactions so 4(i.e. B S B S)
            return 0; 
        
        if(dp[index][trans] != -1)
            return dp[index][trans];
        
        int profit = 0;
        //trans will be even when we will perform buy and odd when we will perform sell
        if(trans%2 == 0)  //buy 
        {
            int val1 = -prices[index] + solve(index+1, trans+1, prices, dp); //buy(take)
            int val2 = 0 + solve(index+1, trans, prices, dp); //notBuy(notTake)
            profit = max(val1, val2);
        }
        else //sell so +ve profit
        {
            int v1 = prices[index] + solve(index+1, trans+1, prices, dp); //sell
            int v2 = 0 + solve(index+1, trans, prices, dp); //not sell
            profit = max(v1, v2);
        }
            
        return dp[index][trans] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(0, 0, prices, dp);
    }
};