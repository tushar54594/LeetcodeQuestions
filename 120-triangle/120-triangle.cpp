class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp)
    {
        int n = triangle.size();
        //base case
        if(i == n-1)    //if we reach the last row, return whatever element you are at in the last row
            return triangle[n-1][j];
        
        //we will never go out of boundary so only 1 base case
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int v1 = triangle[i][j] + solve(i+1, j, triangle, dp);
        int v2 = triangle[i][j] + solve(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(v1, v2);
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, dp);
    }
};