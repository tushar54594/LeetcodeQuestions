class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.size();
        
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == ' ' && ans > 0)
                return ans;
            if(s[i] != ' ')
                ans++;
        }
        return ans;
    }
};