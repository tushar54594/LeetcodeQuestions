//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9+7;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0 && grid[0][0] == 0) return 1;
        if(i<0 || j<0 || grid[i][j] == 1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = solve(i-1, j, grid, dp);
        int left = solve(i, j-1, grid, dp);
        
        return dp[i][j] = (up + left)%mod;
    }
    
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, grid, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends