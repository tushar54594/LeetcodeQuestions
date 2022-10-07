class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, -1);
        
        for(int i=0; i<m; i++)
        {
            vector<int> curr(n, -1);
            for(int j=0; j<n; j++)
            {
                if(i == 0 && j == 0)
                    curr[j] = grid[0][0];
                else
                {
                    int top = 1e9, left = 1e9;
                    if(i > 0)
                        top = grid[i][j] +  prev[j];
                    if(j > 0)
                        left = grid[i][j] + curr[j-1];
                    curr[j] = min(top, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};