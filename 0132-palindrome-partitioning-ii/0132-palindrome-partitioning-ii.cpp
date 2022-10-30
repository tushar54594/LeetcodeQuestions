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
 
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--)
        {
            int mini = INT_MAX;
            for(int j=i; j<n; j++)
            {
                if(isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j+1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};