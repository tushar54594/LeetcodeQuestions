class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        
        for(auto a : words)
        {
            int len = a.size();
            if(s.substr(0, len) == a) ans++;
        }
        
        return ans;
    }
};