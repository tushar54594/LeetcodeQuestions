class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> after(n+1, 0), curr(n+1, 0);
        
        for(int index=n-1; index>=0; index--)
        {
            for(int prev_index=index-1; prev_index>=-1; prev_index--)
            {
                int notTake = 0 + after[prev_index+1];  //do second parameter +1 since coordinate shift
                int take = 0;
                if(prev_index == -1 || nums[index] > nums[prev_index])
                    take = 1 + after[index+1];

                curr[prev_index+1] = max(notTake, take);
            }
            after = curr;
        }
        return after[-1+1];
    }
};