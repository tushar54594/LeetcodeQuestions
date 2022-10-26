class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadBuy = aheadNotBuy = 0;
        
        for(int index=n-1; index>=0; index--)
        {
            int val1 = -prices[index] + aheadNotBuy; //buy(take)
            int val2 = 0 + aheadBuy; //notBuy(notTake)
            currBuy = max(val1, val2);
               
            int v1 = prices[index] + aheadBuy - fee; //sell
            int v2 = 0 + aheadNotBuy; //not sell
            currNotBuy = max(v1, v2);
            
            aheadNotBuy = currNotBuy;
            aheadBuy = currBuy;
        }
        return aheadBuy;
    }    
};