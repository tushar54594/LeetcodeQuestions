class Solution {
public:
    //variable size sliding window
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        unordered_map<char, int> m;
        
        int count = 0;
        while(j < n)
        {
            if(m.find(s[j]) != m.end())
                m[s[j]]++;
            else
                m[s[j]] = 1;
            
            if(m.size() < 3)
                j++;
            else if(m.size() == 3)
            {
                while(m.size() == 3)
                {
                    count += n-j;
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                        m.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return count;
    }
};