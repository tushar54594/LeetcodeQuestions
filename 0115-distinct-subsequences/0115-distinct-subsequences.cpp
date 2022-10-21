class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<double> prev(m+1, 0), curr(m+1, 0);
        /*
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        base case for tabulation. We are going to every row and initializing 1st value as 1
        so similarly we do initalize to 1 for both prev and curr
        */
        
        //base case
        prev[0] = 1;
        curr[0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1])
                    curr[j] = prev[j] + prev[j-1];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};