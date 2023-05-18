class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            int n = nums[i];
            vector<int> v;
            while(n > 0)
            {
                int digit = n%10;
                v.push_back(digit);
                n /= 10;
            }
            reverse(v.begin(), v.end());
            for(auto a : v) ans.push_back(a);
        }
        
        return ans;
    }
};