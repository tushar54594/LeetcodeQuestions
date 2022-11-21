class Solution {
public:
    string reverseWords(string s) {
        stack<string> stck;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            else
            {
                string word = "";
                while(i<s.size() && s[i] != ' ')
                {
                    word += s[i];
                    i++;
                }
                stck.push(word);
            }
        }
        
        string ans = "";
        while(!stck.empty())
        {
            ans += stck.top();
            stck.pop();
            if(!stck.empty())
                ans += " ";
        }
        
        return ans;
    }
};