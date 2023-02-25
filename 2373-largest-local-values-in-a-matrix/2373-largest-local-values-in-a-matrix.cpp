class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=0; j<ans.size(); j++)
            {
                int maxi = INT_MIN;
                for(int r=i; r<i+3; r++)
                {
                    for(int c=j; c<j+3; c++)
                    {
                        maxi = max(maxi, grid[r][c]);
                    }
                }
                ans[i][j] = maxi;
            }
        }
        return ans;
    }
};