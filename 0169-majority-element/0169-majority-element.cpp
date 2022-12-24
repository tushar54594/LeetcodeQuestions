class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int n = nums.size();
        if(n == 1)
            return 1;
        
        for(int i=1; i<n; i++)
        {
            if(nums[i] == nums[i-1])
                count++;
            else
                count = 1;
            
            if(count > n/2)
                return nums[i];
        }
        return -1;
    }
};