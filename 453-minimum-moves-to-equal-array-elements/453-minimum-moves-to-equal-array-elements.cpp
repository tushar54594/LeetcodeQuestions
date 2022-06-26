class Solution {
public:
    int minMoves(vector<int>& nums) {
        //step1(find the minimum element)
        int min = *min_element(nums.begin(), nums.end());
        //step2(difference between every element and the minimum element)
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] -= min;
        }
        //step3
        return accumulate(nums.begin(),nums.end(),0);
        
    }
};