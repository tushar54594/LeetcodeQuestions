class Solution {
public:
    int f(int i, int n, int k, vector<int>& arr, vector<int> &dp)
    {
        //base case
        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = INT_MIN;
        int len = 0, maxi = INT_MIN;
        for(int j=i; j<min(n, i+k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len*maxi + f(j+1, n, k, arr, dp); //subarraySum = len*maxValue
            ans = max(ans, sum);
        }
        return dp[i] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, n, k ,arr, dp);
    }
};