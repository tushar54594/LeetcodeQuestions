class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int maxi = 1;
        int count = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                continue;
            else if(nums[i] == nums[i-1]+1)
            {
                count++;
                maxi = max(maxi, count);
            }
            else if(nums[i] != nums[i-1]+1)
                count = 1;
        }
        return maxi;
    }
};