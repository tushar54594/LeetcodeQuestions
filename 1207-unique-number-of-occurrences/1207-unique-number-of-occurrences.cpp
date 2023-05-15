class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto a : arr)
        {
            mp[a]++;
        }
        
        int n = mp.size();
        set<int> s;
        for(auto a : mp) s.insert(a.second);
        
        if(s.size() == n) return true;
        
        return false;
    }
};