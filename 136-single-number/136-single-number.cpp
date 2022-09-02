class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //move 2 times ahead in every iteration since adjacent elements should be equal
        for(int i=1; i<nums.size(); i+=2)
        {
            if(nums[i] != nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};