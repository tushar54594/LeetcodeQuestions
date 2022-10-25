class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        
        //base case
        ahead[0] = ahead[1] = 0;
        
        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                int profit = 0;
                if(buy) 
                {
                    int val1 = -prices[index] + ahead[0]; //buy(take)
                    int val2 = 0 + ahead[1]; //notBuy(notTake)
                    profit = max(val1, val2);
                }
                else //sell so +ve profit
                {
                    int v1 = prices[index] + ahead[1]; //sell
                    int v2 = 0 + ahead[0]; //not sell
                    profit = max(v1, v2);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};