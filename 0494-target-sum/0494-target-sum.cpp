class Solution {
public:
    int solve(int index, int target, vector<int> &num, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(target == 0 && num[0] == 0)
                return 2;  //we will have 2 ways either take it or not take it
            if(target == 0 || target == num[0])
                return 1;

            return 0;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        int notTake = solve(index-1, target, num, dp);
        int take = 0;
        if(num[index] <= target)
            take = solve(index-1, target-num[index], num, dp);

        return dp[index][target] = (notTake + take);
    }
 
    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        return solve(n-1, tar, num, dp);
    }
    
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for(int i=0; i<n; i++)
            totalSum += arr[i];

        //edge case
        if((totalSum - d < 0) || ((totalSum-d) %2 != 0))
            return 0;

        return findWays(arr, (totalSum-d)/2);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};