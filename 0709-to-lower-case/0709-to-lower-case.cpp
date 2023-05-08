class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for(auto a : s) ans += tolower(a);
        return ans;
    }
};