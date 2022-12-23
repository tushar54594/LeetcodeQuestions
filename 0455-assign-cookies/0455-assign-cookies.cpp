class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        
        // sort(g.begin(), g.end(), greater<int>());
        // sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end());
        reverse(g.begin(), g.end());
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        
        int ans = 0;
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            if(s[j] >= g[i])
            {
                ans++;
                i++;
                j++;
            }
            else
                i++;
        }
        return ans;
    }
};