class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int freq = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(candidate == nums[i])
                freq++;
            else
            {
                freq--;
                if(freq == 0)
                {
                    candidate = nums[i];
                    freq = 1;
                }
            }
        }
        
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == candidate)
                count++;
        }
        
        if(count > nums.size()/2)
            return candidate;
        return -1;
    }
};