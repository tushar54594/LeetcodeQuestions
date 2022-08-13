class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int flag = 1;
        while(flag)
        {
            for(int i=0; i<nums.size(); i++)
            {
                flag = 0;
                if(nums[i] == original)
                {
                    original *= 2;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                return original;
        }
        return original;
    }
};