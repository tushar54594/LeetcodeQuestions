class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len = pref.size();
        
        int ans = 0;
        for(auto a : words)
        {
            if(a.substr(0, len) == pref) ans++;
        }
        
        return ans;
    }
};