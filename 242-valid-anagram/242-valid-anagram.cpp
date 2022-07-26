class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        vector<int> arr(26,0); //since only lowercase english letters are present
        for(int i=0; i<s.size(); i++)
        {
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        
        //if the strings are anagrams. then each index of array will have 0 value so if any index have non zero value, then it is not an anagram
        for(int i=0; i<26; i++)
        {
            if(arr[i])
                return false;
        }
        
        return true;
    }
};