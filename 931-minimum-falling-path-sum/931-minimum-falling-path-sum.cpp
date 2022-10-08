class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, -1);
        
        for(int j=0; j<n; j++)
            prev[j] = matrix[0][j];
        
        for(int i=1; i<n; i++)
        {
            vector<int> curr(n, -1);
            for(int j=0; j<n; j++)
            {
                int v1 = 1e9;
                if(j > 0)
                    v1 = matrix[i][j] + prev[j-1];
                int v2 = matrix[i][j] + prev[j];
                int v3 = 1e9;
                if(j < n-1)
                    v3 = matrix[i][j] + prev[j+1];
                curr[j] = min(v1, min(v2, v3));
            }
            prev = curr;
        }
        
        int mini = INT_MAX;
        for(int j=0; j<n; j++)
            mini = min(mini, prev[j]);
        
        return mini;
    }
};