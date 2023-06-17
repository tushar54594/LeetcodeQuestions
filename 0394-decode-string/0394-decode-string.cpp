class Solution {
public:
    string solve(string &s, int& i)
    {
        string result;
        while(i < s.size() && s[i] != ']')
        {
            if(isdigit(s[i]))
            {
                int k = 0;
                while(i < s.size() && isdigit(s[i]))
                {
                    k = k*10 + (s[i] - '0');
                    i++;
                }
                    
                i++;  //skip opening bracket
                
                string r = solve(s, i);
                while(k--)
                    result += r;
                
                i++;  //skip closing bracket
            }
            else
            {
                result += s[i];
                i++;
            }
        }
        return result;
    }
    
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};