class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, int n, vector<vector<int>> &dp)
    {
        //base cases
        if(j < 0 || j > n-1)
            return 1e9;
        if(i == 0)
            return matrix[0][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int v1 = matrix[i][j] + solve(i-1, j-1, matrix, n, dp);
        int v2 = matrix[i][j] + solve(i-1, j, matrix, n, dp);
        int v3 = matrix[i][j] + solve(i-1, j+1, matrix, n, dp);
        
        return dp[i][j] = min(v1, min(v2, v3));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int j=0; j<n; j++)
        {
            int val = solve(n-1, j, matrix, n, dp);
            ans = min(ans, val);
        }
        return ans;
    }
};