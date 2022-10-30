class Solution {
public:
    bool isPalindrome(int start, int end, string &s)
    {
        while(start<end)
        {
            if(s[start] != s[end])
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
    
    int f(int i, int n, string &s, vector<int> &dp)
    {
        //base case
        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int mini = INT_MAX;
        for(int j=i; j<n; j++)
        {
            if(isPalindrome(i, j, s))
            {
                int cost = 1 + f(j+1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }
};