class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp)
    {
        if(m>=0 && n>=0 && obstacleGrid[m][n] == 1)
            return 0;
        if(m == 0 && n == 0) 
            return 1;
        if(m < 0 || n < 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int top = solve(m-1, n, obstacleGrid, dp);
        int left = solve(m, n-1, obstacleGrid, dp);
        
        return dp[m][n] = top + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, obstacleGrid, dp);
    }
};