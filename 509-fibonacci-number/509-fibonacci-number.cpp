class Solution {
public:
    int fibonacci(int n, vector<int> &dp)
    {
        if(n <= 1)
            return n;
        
        //checking if subproblem has been previously solved
        if(dp[n] != -1)
            return dp[n];
        
        //storing the ans which is computed for every subproblem
        return dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
    }
    
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fibonacci(n, dp);
    }
};