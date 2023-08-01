class Solution {
public:
    
    void solve(int ind, vector<int> &v, vector<vector<int>> &ans, int k, int n)
    {
        if(ind == n+1){
            if(v.size() == k) ans.push_back(v);
            return;
        }
        
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        
        v.push_back(ind);
        solve(ind+1, v, ans, k, n);
        v.pop_back();
        solve(ind+1, v, ans, k, n);
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        
        solve(1, v, ans, k, n);
        
        return ans;
    }
};