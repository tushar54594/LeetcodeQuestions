class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
    
        vector<char> ans(n, ' ');
        for(int i=0; i<n; i++)
        {
            ans[indices[i]] = s[i]; 
        }
        
        string str = "";
        for(auto a : ans)
            str += a;
        
        return str;
    }
};