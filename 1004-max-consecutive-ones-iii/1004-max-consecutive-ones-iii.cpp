class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int i = 0;
        int j = 0;
        
        int maxi = INT_MIN;
        while(j < nums.size())
        {
            m[nums[j]]++;
            if(m[0] <= k)
            {
                maxi = max(maxi, j-i+1);
                j++;
            }
            else if(m[0] > k)
            {
                while(m[0] > k)
                {
                    m[nums[i]]--;
                    i++;
                }
                
                if(m[0] == k)
                    maxi = max(maxi, j-i+1);
                
                j++;
            }
        }
        return maxi;
    }
};