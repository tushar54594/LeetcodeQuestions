class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0; //for counting the depriciation points
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > nums[(i+1)%nums.size()])
                count++;
        }
        if(count > 1)
            return false;
        
        return true;
    }
};