class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>>& grid, int n, int m)
    {
        //out of bound cases(base case)
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1 || grid[i][j] == '0')
            return;
        
        vis[i][j] = 1;
        
        dfs(i-1, j, vis, grid, n, m);
        dfs(i+1, j, vis, grid, n, m);
        dfs(i, j+1, vis, grid, n, m);
        dfs(i, j-1, vis, grid, n, m);
    }
    
    int numIslands(vector<vector<char>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && isConnected[i][j] == '1')
                {
                    dfs(i, j, vis, isConnected, n, m);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};