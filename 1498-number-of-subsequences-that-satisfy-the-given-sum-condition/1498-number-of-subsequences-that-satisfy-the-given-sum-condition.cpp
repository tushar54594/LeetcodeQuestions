class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = (int)1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pow(n);
        pow[0] = 1;
        
        for(int i=1; i<n; i++) pow[i] = 2*pow[i-1]%mod;
        
        int ans = 0;
        int s = 0;
        int e = n-1;
        while(s <= e)
        {
            if(nums[s] + nums[e] <= target)
            {
                ans = (ans + pow[e-s])%mod;
                s++;
            }
            else 
                e--;
        }
        return ans;
    }
};