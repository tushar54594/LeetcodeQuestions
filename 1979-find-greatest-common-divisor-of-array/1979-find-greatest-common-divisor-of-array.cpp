class Solution {
public:
    int gcd(int m, int n)
    {
        while(n != 0)
        {
            int r = m%n;
            m = n;
            n = r;
        }
        return m;
    }
    
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums[0];
        int n = nums[nums.size()-1];
        return gcd(m,n);
    }
};