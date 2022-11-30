class Solution {
public:
    int countGoodSubstrings(string s) {
        int i = 0;
        int j = 0;
        
        int ans = 0;
        unordered_map<char, int> m;
        while(j < s.size())
        {
            if(m.find(s[j]) == m.end())
                m[s[j]] = 1;
            else
                m[s[j]]++;
            
            if(j-i+1 < 3)
                j++;
            else if(j-i+1 == 3)
            {
                if(m.size() == 3)
                    ans++;
                
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                
                i++;
                j++;
            }
        }
        return ans;
    }
};