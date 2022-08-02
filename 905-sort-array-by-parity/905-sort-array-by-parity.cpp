class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        
        int a = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%2 == 0)
            {
                swap(nums[i], nums[a]);
                a++;
            }
        }
        return nums;
    }
};