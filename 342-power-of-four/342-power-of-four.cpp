class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0; i<sqrt(n); i++)
        {
            if(pow(4,i) == n)
                return true;
        }
        return false;
    }
};