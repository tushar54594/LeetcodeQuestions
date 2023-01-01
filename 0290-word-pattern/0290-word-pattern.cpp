class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string w = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != ' ')
                w += s[i];
            else
            {
                v.push_back(w);
                w = "";
            }
        }
        v.push_back(w);
        
        if(pattern.size() != v.size())
            return false;
        
        unordered_map<char, string> m;
        for(int i=0; i<pattern.size(); i++)
        {
            if(m.find(pattern[i]) == m.end())
                m[pattern[i]] = v[i];
            else
            {
                if(m[pattern[i]] != v[i])
                    return false;
            }
        }
        
        unordered_map<string, char> m1;
        for(int i=0; i<v.size(); i++)
        {
            if(m1.find(v[i]) == m1.end())
                m1[v[i]] = pattern[i];
            else
            {
                if(m1[v[i]] != pattern[i])
                    return false;
            }
        }
        
        return true;
    }
};