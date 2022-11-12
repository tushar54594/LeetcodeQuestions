class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        
        while(n--)  //run the loop n times
        {
            for(int j=1; j<5; j++)
            {
                dp[j] = dp[j-1] + dp[j];
            }
        }
        
        return dp[4];
    }
};