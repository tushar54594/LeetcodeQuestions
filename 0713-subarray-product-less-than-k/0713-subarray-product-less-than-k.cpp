class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        if(k == 0) return 0;
        
        int n = a.size();
        int p = 1;
        int i = n-1;
        int j = n-1;
        int ans = 0;
        while(i >= 0)
        {
            p *= a[i];
            if(p < k) ans += j-i+1;
            else if(p >= k)
            {
                while(p >= k && i<=j)
                {
                    p /= a[j];
                    j--;
                }
                ans += j-i+1;
            }
            i--;
        }
        return ans;
    }
};