class Solution {
public:
    bool isPalindrome(string s)
    {
        int start = 0, end = s.length()-1;
        while(start<=end)
        {
            if(s[start] != s[end])
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(isPalindrome(s))
            return 1;
        else
            return 2;
    }
};