class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> freq(26, 0);
        for(auto a : allowed) freq[a - 'a'] = 1;
        
        int ans = 0;
        for(auto a : words)
        {
            int flag = 1;
            for(auto c : a)
            {
                if(freq[c - 'a'] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans++;
        }
        
        return ans;
    }
};