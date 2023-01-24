class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> m;
        for(auto a : s)
            m[a]++;
        
        int freq = m[s[0]];
        for(auto a : m)
        {
            if(freq != a.second)
                return false;
        }
        return true;
    }
};