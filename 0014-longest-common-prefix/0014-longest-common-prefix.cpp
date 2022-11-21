class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
            return "";
        if(n == 1)
            return strs[0];
        
        sort(strs.begin(), strs.end());
        
        string a = strs[0];
        string b = strs[n-1];
        
        string ans = "";
        for(int i=0; i<a.size(); i++)  //since length of a will be smaller
        {
            if(a[i] == b[i])
                ans += a[i];
            else
                break;
        }
        
        return ans;
    }
};