class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        map<char, int> mp;
        for(int i=0; i<m; i++)
            mp[p[i]]++;
        
        int i = 0;
        int j = 0;
        int count = mp.size();
        while(j < n)
        {
            if(mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            if(j-i+1 < m)
                j++;
            else if(j-i+1 == m)
            {
                if(count == 0)
                    ans.push_back(i);
                if(mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};