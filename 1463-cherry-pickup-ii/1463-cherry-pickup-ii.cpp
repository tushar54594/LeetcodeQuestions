class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        //base cases
        if(j1 < 0 || j1 > n-1 || j2 < 0 || j2 > n-1)
            return -1e9;  //we want max so we are returning -1e9 
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        //there is no need for i1 and i2 because i will be same only because both robot 1 and 2 will move simultaneouly to the next row
        if(i == m-1)
        {
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        //for every movement of robot1, there are 3 simultaneous movements of robot2
        //there are 3 movements of robot1
        //so in total there will be 9 combos 
        int maxi = 0;
        for(int dj1 = -1; dj1<=1; dj1++)
        {
            for(int dj2 = -1; dj2<=1; dj2++)
            {
                if(j1 == j2)
                    maxi = max(maxi, grid[i][j1] + solve(i+1, j1+dj1, j2+dj2, grid, dp));
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2]+ solve(i+1, j1+dj1, j2+dj2, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(m, vector<int>(n, -1)));
        return solve(0, 0, n-1, grid, dp);
    }
};