class Solution {
public:  
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);
        
        //base case
        for(int t = 0; t<=amount; t++)
        {
            if(t%coins[0] == 0)
                prev[t] = 1;
            else 
                prev[t] = 0;  //else is not needed as already array is initialized to 0
        }
        
        for(int index=1; index<n; index++)
        {
            vector<int> curr(amount+1, 0);
            for(int target=0; target<=amount; target++)
            {
                int notTake = prev[target];
                int take = 0;
                if(coins[index] <= target)
                    take = curr[target-coins[index]]; //it will be index not index-1

                curr[target] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};