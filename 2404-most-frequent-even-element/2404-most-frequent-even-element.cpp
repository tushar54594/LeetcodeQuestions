class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%2 == 0)
            {
                if(m.find(nums[i]) != m.end())
                    m[nums[i]]++;
                else
                    m[nums[i]] = 1;
            }
        }
        
        int maxi = INT_MIN;
        int ans = -1;
        for(auto a : m)
        {
            if(a.second > maxi)
            {
                maxi = a.second;
                ans = a.first;
            }
        }
        return ans;
    }
};