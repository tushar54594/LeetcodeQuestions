class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        vector<int> arr(26,0);
        for(int i=0; i<s.size(); i++)
        {
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(arr[i])
                return false;
        }
        
        return true;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        
        for(int i=1; i<words.size(); i++)
        {
            if(isAnagram(words[i-1], words[i]))
                continue;
            else
                ans.push_back(words[i]);
        }
        return ans;
    }
};