class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stck;
        string ans;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                if(stck.size() > 0)   //it is not outermost(size == 0 matlab outermost hai)
                    ans += s[i];
                stck.push(s[i]);
            }
            else
            {
                stck.pop();
                if(stck.size() > 0)   //it is not outermost
                    ans += s[i];
            }
        }
        
        return ans;
    }
};