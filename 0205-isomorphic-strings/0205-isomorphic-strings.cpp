class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,int> s_to_t_map;
        unordered_map<char,int> t_to_s_map;
        
        for (int i = 0; i < n; i++) {
            if (s_to_t_map[s[i]] != t_to_s_map[t[i]])
                return false;
                
            s_to_t_map[s[i]] = t_to_s_map[t[i]] = i + 1;
        }

        return true;
    }
};