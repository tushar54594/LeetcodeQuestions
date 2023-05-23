class Solution {
public:
    int solve(int i, string s, vector<int> &dp)
    {
        if(s[i] == '0') return 0;
        if(i == s.size()) return 1;
        
        if(dp[i] != -1) return dp[i];
        
        int takeOneDigit = solve(i+1, s, dp);
        int takeTwoDigit = 0;
        if(i+1<s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
        {
            takeTwoDigit = solve(i+2, s, dp);
        }
        
        return dp[i] = takeOneDigit + takeTwoDigit;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return solve(0, s, dp);
    }
};

/*
Two ways
1. Take a single digit
2. Take 2 digits

If we get 0, then we cannot decode the no
*/