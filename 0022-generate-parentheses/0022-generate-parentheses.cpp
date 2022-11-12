class Solution {
public:
    void f(int oc, int cc, vector<string> &ans, int n, string s)
    {
        if(oc == n && cc == n)
        {
            ans.push_back(s);
            return;
        }
        
        if(oc < n)
            f(oc+1, cc, ans, n, s + "(");
        
        if(oc > cc)
            f(oc, cc+1, ans, n, s + ")");
    }
    
    
    vector<string> generateParenthesis(int n) {
        int oc = 0;
        int cc = 0;
        
        vector<string> ans;
        f(oc, cc, ans, n, "");
        return ans;
    }
};