class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i=0; i<s.size(); i++)
        {
            if(isalnum(s[i]))
                str.push_back(tolower(s[i]));
        }
        
        int start = 0;
        int end = str.size()-1;
        while(start<end)
        {
            if(str[start] != str[end])
                return false;
            
            start++;
            end--;
        }
        return true;
    }
};