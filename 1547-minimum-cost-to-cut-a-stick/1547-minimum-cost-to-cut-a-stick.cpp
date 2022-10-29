class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>> &dp)
    {
        //base case
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = 1e9;
        for(int index = i; index<=j; index++)
        {
            int cost = cuts[j+1] - cuts[i-1] + f(i, index-1, cuts, dp) + f(index+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        
        cuts.push_back(0);  //insert 0 at front
        cuts.push_back(n);  //insert length of stick at end
        
        sort(cuts.begin(), cuts.end()); //sort the array
        
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return f(1, c, cuts, dp);
    }
};