class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> pos;
        vector<int> neg;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        
        int index = 0;
        for(int i=0; i<nums.size(); i=i+2)
        {
            ans[i] = pos[index++];
        }
        
        index = 0;
        for(int i=1; i<nums.size(); i=i+2)
        {
            ans[i] = neg[index++];
        }
        
        return ans;
    }
};