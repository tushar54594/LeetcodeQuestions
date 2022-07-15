class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        
        while(n>1)
        {
            vector<int> newNums;
            for(int i=0; i<n/2; i++)
            {
                if(i%2 == 0)
                    newNums.push_back(min(nums[2 * i], nums[2 * i + 1]));
                else
                    newNums.push_back(max(nums[2 * i], nums[2 * i + 1]));
            }
            n = n/2;
            nums = newNums;
        }
        return nums[0];
    }
};