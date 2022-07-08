class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        
        string a = "",b = "";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != '#')
                s1.push(s[i]);
            else if(s[i] == '#' && !s1.empty())
                s1.pop();
        }
        
        while(!s1.empty())
        {
            a += s1.top();
            s1.pop();
        }
        
        for(int i=0; i<t.length(); i++)
        {
            if(t[i] != '#')
                s2.push(t[i]);
            else if(t[i] == '#' && !s2.empty())
                s2.pop();
        }
        
        while(!s2.empty())
        {
            b += s2.top();
            s2.pop();
        }
        
        if(a == b)
            return true;
        
        return false;
    }
};