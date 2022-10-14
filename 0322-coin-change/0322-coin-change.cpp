class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);
         
        //base case
        for(int t=0; t<=amount; t++)
        {
            if(t%coins[0] == 0)
                prev[t] = t/coins[0];
            else
                prev[t] = 1e9;
        }
        
        for(int index=1; index<n; index++)
        {
            vector<int> curr(amount+1, 0);
            for(int t = 0; t<=amount; t++)
            {
                int notTake = 0 + prev[t];
                int take = 1e9;
                if(coins[index] <= t)
                    take = 1 + curr[t-coins[index]];
                
                curr[t] = min(notTake, take);
            }
            prev = curr;
        }
        if(prev[amount] == 1e9)
            return -1;
        
        return prev[amount];
    }
};