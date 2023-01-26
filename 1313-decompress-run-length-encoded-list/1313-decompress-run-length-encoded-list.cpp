class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            int freq = nums[i];
            i++;
            int val = nums[i];
            while(freq--)
                ans.push_back(val);
        }
        return ans;
    }
};