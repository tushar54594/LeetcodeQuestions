class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        //base case
        if(j < 0) //it means str2 is found in str1
            return 1;
        if(i < 0)  //it means str1 is exhausted and we have not found str2
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = solve(i-1, j, s, t, dp) + solve(i-1, j-1, s, t, dp);
        else
            return dp[i][j] = solve(i-1, j, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};