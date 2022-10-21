class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0; //minimum profit will be 0 if we buy and sell on the same day
        
        for(int i=1; i<prices.size(); i++)
        {
            int cost = prices[i] - mini; //sell - buy
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};