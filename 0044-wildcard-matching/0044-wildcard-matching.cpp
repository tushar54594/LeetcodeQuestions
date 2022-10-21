class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        //base case
        dp[0][0] = true;
        for(int i=1; i<=n; i++)
            dp[i][0] = false;
        for(int j=1; j<=m; j++)
        {
            dp[0][j] = true;
            for(int a=1; a<=j; a++)
            {
                if(p[a-1] != '*')
                {
                    dp[0][j] = false;
                    break;
                }
            }
        }
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};