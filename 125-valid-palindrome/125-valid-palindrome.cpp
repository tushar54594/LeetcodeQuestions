class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<end)
        {
            //if the element is not an alphabet then ignore
            if(!isalnum(s[start]))
                start++;
            //if the element is not an alphabet then ignore
            else if(!isalnum(s[end]))
                end--;
            else if(tolower(s[start]) != tolower(s[end]))
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
};