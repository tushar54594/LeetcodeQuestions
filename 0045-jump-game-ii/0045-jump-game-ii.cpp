class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++) nums[i] = max(nums[i]+i, nums[i-1]);
        
        int jumps = 0;
        int i = 0;
        while(i < n-1){
            jumps++;
            i = nums[i];
        }
        
        return jumps;
    }
};