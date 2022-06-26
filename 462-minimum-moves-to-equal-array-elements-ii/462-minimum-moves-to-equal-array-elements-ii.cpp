class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //step1
        sort(nums.begin(),nums.end());
        //step2
        int n = nums.size();
        int mid = nums[n/2];
        //step3
        for(int i=0; i<n; i++)
            nums[i] = abs(nums[i]-mid);
        //step4
        return accumulate(nums.begin(),nums.end(),0);
        
    }
};