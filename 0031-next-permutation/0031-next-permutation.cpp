class Solution {
public:
    //4 steps algo:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index1, index2;
        
        //step1(find the breakpoint)
        for(index1 = n-2; index1>=0; index1--)
        {
            if(nums[index1] < nums[index1 + 1])
                break;
        }
        //edge case(If there is no breakpint) -> means it is the last permutation. Thus return the first one
        if(index1 < 0)
            reverse(nums.begin(), nums.end());
        
        //step2(find the no just greater than the breakpoint)
        else
        {
            for(index2 = n-1; index2>index1; index2--)
            {
                if(nums[index2] > nums[index1])
                    break;
            }
            //step3(swap the two nos)
            swap(nums[index1], nums[index2]);
            //step4(arrange the rest of the elements after breakpoint in sorted manner(Just reverse it))
            reverse(nums.begin() + index1 + 1, nums.end());
        }
    }
};