class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        
        for(auto i : strs)
        {
            string temp = i;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        
        for(auto i : mp)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
};