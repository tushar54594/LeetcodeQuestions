class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //Step1
        int currSum = 0;
        int ans1 = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            currSum += nums[i];
            ans1 = max(ans1, currSum);
            
            if(currSum < 0)
                currSum = 0;
        }
        cout<<ans1<<endl;
        //Step2
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        cout<<totalSum<<endl;
        //Step3
        currSum = 0;
        int minSum = INT_MAX;
        for(int i = 0; i<nums.size(); i++)
        {
            currSum += nums[i];
            minSum = min(minSum, currSum);
            
            if(currSum > 0)
                currSum = 0;
        }
        
        if(minSum == totalSum)
            return ans1;
        //Step4
        int ans2 = totalSum - minSum;
        cout<<ans2<<endl;
        return max(ans1, ans2);
    }
};



//Idea
/*
1. Calculate max subarray sum using Kadane algo(This can be one of the answers - ans1)
2. Calculate TotalSum
3. Calculate min subarray sum using Kadane algo
4. Calculate TotalSum - minSubarraySum(This can be one of the answers - ans2)
5. Final Ans = max(ans1, ans2)
*/