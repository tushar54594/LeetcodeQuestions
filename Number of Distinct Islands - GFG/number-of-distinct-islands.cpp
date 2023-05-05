//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //row0 and col0 are base(starting)
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>& grid, vector<pair<int,int>> &v, int row0, int col0)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1 || grid[i][j] != 1) return;
        
        vis[i][j] = 1;
        v.push_back({i-row0, j-col0});
        
        dfs(i+1, j, vis, grid, v, row0, col0);
        dfs(i-1, j, vis, grid, v, row0, col0);
        dfs(i, j+1, vis, grid, v, row0, col0);
        dfs(i, j-1, vis, grid, v, row0, col0);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        set<vector<pair<int,int>>> s;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>> v;
                    dfs(i, j, vis, grid, v, i, j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends