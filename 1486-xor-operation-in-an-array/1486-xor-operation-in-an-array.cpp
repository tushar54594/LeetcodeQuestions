class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> v(n, 0);
        for(int i=0; i<n; i++)
        {
            v[i] = start + 2 * i;
        }
        
        int ans = v[0];
        for(int i=1; i<n; i++)
            ans ^= v[i];
        
        return ans;
    }
};