class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        //base case
        //both the strings have to be exhausted for the comparison to be true
        if(j<0 && i<0)
            return true;
        //if the pattern is exhausted but the string is still left, return false
        if(j<0 && i>=0)
            return false;
        //if string is exhausted but pattern is left, then the pattern string should only have '*' then only            it can match with the empty string
        if(i<0 && j>=0)
        {
            for(int a=0; a<=j; a++)
            {
                if(p[a] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        if(p[j] == '*')
        {
            return dp[i][j] = solve(i, j-1, s, p, dp) || solve(i-1, j, s, p, dp);
        }
        
        return false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, p, dp);
    }
};