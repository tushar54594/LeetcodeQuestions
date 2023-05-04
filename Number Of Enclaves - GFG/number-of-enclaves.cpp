//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1 || board[i][j] == 0) 
            return;
        
        vis[i][j] = 1;
        
        dfs(i-1, j, vis, board);
        dfs(i+1, j, vis, board);
        dfs(i, j-1, vis, board);
        dfs(i, j+1, vis, board);
    }
    
    int numberOfEnclaves(vector<vector<int>> &board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //traverse on 1st row, 1st col, last row, last col
        
        //traverse first row and last row
        for(int j=0; j<m; j++)
        {
            //first row
            if(!vis[0][j] && board[0][j] == 1) dfs(0, j, vis, board);
            //last row
            if(!vis[n-1][j] && board[n-1][j] == 1) dfs(n-1, j, vis, board);
        }
        
        //traverse first col and last col
        for(int i=0; i<n; i++)
        {
            //first col
            if(!vis[i][0] && board[i][0] == 1) dfs(i, 0, vis, board);
            //last col
            if(!vis[i][m-1] && board[i][m-1] == 1) dfs(i, m-1, vis, board);    
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && board[i][j] == 1)
                    ans++;
            }
        }
        
        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends