class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        unordered_map<char, int> m;
        int maxi = 0;
        
        while(j < s.size())
        {
            if(m.find(s[j]) != m.end())
                m[s[j]]++;
            else
                m[s[j]] = 1;
            
            if(m.size() == j-i+1)
            {
                maxi = max(maxi, j-i+1);
                j++;
            }
            else if(m.size() < j-i+1)
            {
                while(m.size() < j-i+1)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                        m.erase(s[i]);
                    i++;
                }
                
                if(m.size() == j-i+1)
                    maxi = max(maxi, j-i+1);
                j++;
            }
        }
        return maxi;
    }
};