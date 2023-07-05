class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        if(dp[n] != -1) return dp[n];
        
        int ans = n;  //max ans will be n only(1^2 + 1^2 .. n times)
        for(int i=1; i*i<=n; i++){
            ans = min(ans, 1 + solve(n - i*i, dp));
        }
        
        return dp[n] = ans;
    }
    
    
    int numSquares(int n) {
        if(ceil(sqrt(n)) == floor(sqrt(n))) return 1; //if n is itself perfect square
        
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};