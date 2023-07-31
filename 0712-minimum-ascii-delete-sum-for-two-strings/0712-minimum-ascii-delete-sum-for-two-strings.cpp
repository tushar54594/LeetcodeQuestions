class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, int m, int n, vector<vector<int>> &dp){
        if(i>=m && j>=n) return 0;
        
        else if(i>=m) return s2[j] + solve(i, j+1, s1, s2, m, n, dp);
        else if(j>=n) return s1[i] + solve(i+1, j, s1, s2, m, n, dp);
        
        else if(s1[i] == s2[j]) return solve(i+1, j+1, s1, s2, m, n, dp);
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int delete_s1 = s1[i] + solve(i+1, j, s1, s2, m, n, dp);
        int delete_s2 = s2[j] + solve(i, j+1, s1, s2, m, n, dp);
        
        return dp[i][j] = min(delete_s1, delete_s2);
    }
    
    
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(0, 0, s1, s2, m, n, dp);
    }
};