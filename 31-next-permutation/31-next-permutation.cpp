class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index1, index2;
        
        //step1
        for(index1 = n-2; index1>=0; index1--)
        {
            if(nums[index1] < nums[index1 + 1])
                break;
        }
        //edge case(If there is no breakpint)
        if(index1 < 0)
            reverse(nums.begin(), nums.end());
        
        //step2
        else
        {
            for(index2 = n-1; index2>index1; index2--)
            {
                if(nums[index2] > nums[index1])
                    break;
            }
            //step3
            swap(nums[index1], nums[index2]);
            //step4
            reverse(nums.begin() + index1 + 1, nums.end());
        }
    }
};