class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //sort the array
        
        int n = nums.size();
        vector<int> dp(n, 1), hash(n); //initialize the dp array to 1
        int maxi = 1;
        int lastIndex = 0;
        for(int index=1; index<n; index++)
        {
            hash[index] = index;
            for(int prev=0; prev<index; prev++)
            {
                if(nums[index]%nums[prev] == 0 && 1 + dp[prev] > dp[index])
                {
                    dp[index] = 1 + dp[prev];
                    hash[index] = prev;
                }
            }
            if(dp[index] > maxi)
            {
                maxi = dp[index];
                lastIndex = index;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        
        return temp;
    }
};