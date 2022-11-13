class Solution {
public:
    string reverseWords(string s) {
        stack<string> stck;
        for(int i=0; i<s.length(); i++)
        {
            string word = "";
            if(s[i] == ' ')
                continue;
            while(i<s.length() && s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            stck.push(word);
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