class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int p = s1.size();
        map<char, int> m;
        for(int i=0; i<s1.size(); i++)
            m[s1[i]]++;
        
        int i = 0;
        int j = 0;
        int count = m.size();
        while(j < s2.size())
        {
            if(m.find(s2[j]) != m.end())
            {
                m[s2[j]]--;
                if(m[s2[j]] == 0)
                    count--;
            }
            if(j-i+1 < p)
                j++;
            else if(j-i+1 == p)
            {
                if(count == 0)
                    return true;
                if(m.find(s2[i]) != m.end())
                {
                    m[s2[i]]++;
                    if(m[s2[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};