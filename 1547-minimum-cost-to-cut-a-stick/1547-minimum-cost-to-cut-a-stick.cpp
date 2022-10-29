class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        
        cuts.push_back(0);  //insert 0 at front
        cuts.push_back(n);  //insert length of stick at end
        
        sort(cuts.begin(), cuts.end()); //sort the array
        
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        //make the entire vector 0 so no need to write base case seperately
        //for i=c, dp[index][j] can be dp[c+1][j] so thus we need c+2
        
        for(int i=c; i>=1; i--)
        {
            for(int j=i; j<=c; j++)
            {
                int mini = 1e9;
                for(int index = i; index<=j; index++)
                {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};