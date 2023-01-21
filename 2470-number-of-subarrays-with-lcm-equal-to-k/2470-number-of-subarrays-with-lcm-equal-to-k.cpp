class Solution {
public:
    long long int gcd(int a, int b) {
       if (b == 0)
       return a;
       return gcd(b, a % b);
    }
    
    long long int lcm(int a, int b)
    {
        return (a/gcd(a, b)) * b;
    }
    
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            long long int val = nums[i];
            for(int j=i; j<n; j++)
            {
                val = lcm(val, nums[j]);
                if(val == k)
                    ans++;
            }
        }
        return ans;
    }
};