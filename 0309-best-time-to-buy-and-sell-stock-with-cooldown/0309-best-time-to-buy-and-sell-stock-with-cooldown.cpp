class Solution {
public:  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> curr(2, 0);
        
        for(int index=n-1; index>=0; index--)
        {
            int val1 = -prices[index] + front1[0]; //buy(take)
            int val2 = 0 + front1[1]; //notBuy(notTake)
            curr[1]= max(val1, val2);
                
                
            int v1 = prices[index] + front2[1]; //sell
            int v2 = 0 + front1[0]; //not sell
            curr[0] = max(v1, v2);
            
            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};