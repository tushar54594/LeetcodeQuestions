class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int j=0; j<n; j++)
            dp[0][j] = matrix[0][j];
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int v1 = 1e9;
                if(j > 0)
                    v1 = matrix[i][j] + dp[i-1][j-1];
                int v2 = matrix[i][j] + dp[i-1][j];
                int v3 = 1e9;
                if(j < n-1)
                    v3 = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(v1, min(v2, v3));
            }
        }
        
        int mini = INT_MAX;
        for(int j=0; j<n; j++)
            mini = min(mini, dp[n-1][j]);
        
        return mini;
    }
};