class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count_of_negative = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                return 0;
            if(nums[i] < 0)
                count_of_negative++;
        }
        if(count_of_negative%2 == 0)
            return 1;
        else
            return -1;
    }
};