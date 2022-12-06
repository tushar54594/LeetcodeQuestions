class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> m;
        int n = names.size();
        for(int i=0; i<n; i++)
            m.insert({heights[i], names[i]});
        
        vector<string> ans(n);
        int index = n-1;
        for(auto a : m)
            ans[index--] = a.second;
        
        return ans;
    }
};