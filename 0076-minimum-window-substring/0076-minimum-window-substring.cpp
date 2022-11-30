class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(int i=0; i<t.size(); i++)
            m[t[i]]++;
        
        int i = 0;
        int j = 0;
        int mini = INT_MAX;
        int count = m.size();
        int start = 0;
        
        while(j < s.size())
        {
            if(m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if(m[s[j]] == 0)
                    count--;
            }
            
            if(count > 0)
                j++;
            else if(count == 0)
            {
                if(j-i+1 < mini)
                {
                    mini = j-i+1;
                    start = i;
                }
                while(count == 0)
                {
                    if(m.find(s[i]) == m.end()) //not present in map, thus no need
                    {
                        i++;
                        if(j-i+1 < mini)
                        {
                            mini = j-i+1;
                            start = i;
                        }
                    }
                    else
                    {
                        m[s[i]]++;
                        if(m[s[i]] == 1)
                        {
                            count++;
                            if(j-i+1 < mini)
                            {
                                mini = j-i+1;
                                start = i;
                            }
                        }
                        i++;
                    }
                }
                j++;
            }
        }
        
        if(mini != INT_MAX)
            return s.substr(start, mini);
        else
            return "";
    }
};