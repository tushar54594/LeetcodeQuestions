class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        
        if(n < k)
            return {};
        
        unordered_map<char, int> mp;
        for(int i=0; i<k; i++)
            mp[p[i]]++;
        
        vector<int> ans;
        
        int i=0;
        int j=0;
        int count = mp.size();
        
        while(j < n)
        {
            if(mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
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