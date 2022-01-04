class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long temp = x;
        long rev = 0;
        while(temp != 0){
            int digit = temp%10;
            rev = rev*10 + digit;
            temp  = temp/10;
        }
        if(rev == x)
            return true;
        else
            return false;
    }
};