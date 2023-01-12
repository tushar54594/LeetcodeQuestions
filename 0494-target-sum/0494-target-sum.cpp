class Solution {
public:
    int solve(int index, vector<int>& nums, int target)
    {
        if(index == 0)
        {
            if(target == nums[0] || target == -nums[0])
                return 1;
            return 0;
        }
        
        int pos = solve(index-1, nums, target - nums[index]);
        int neg = solve(index-1, nums, target + nums[index]);
        return pos + neg;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = solve(n-1, nums, target);
        if(nums[0] == 0)
            return 2*ans;
        
        return ans;
    }
};