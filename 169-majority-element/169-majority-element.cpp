class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x : nums)
        {
            m[x]++;
            if(m[x] > nums.size()/2)
                return x;
        }
        return 0;
    }
};