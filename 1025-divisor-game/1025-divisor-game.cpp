class Solution {
public:
    bool solve(int n, vector<int> &dp)
    {
        if(n == 1)
            return false;
        if(dp[n] != -1)
            return dp[n];
        else
        {
            for(int i=1; i*i<=n; i++)
            {
                if(n%i == 0)
                {
                    if(solve(n-i, dp) == false) 
                        return dp[n] = true;
                }
            }
            return dp[n] = false;
        }
    }
    
    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};