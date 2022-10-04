class Solution {
public:
    int fib(int n) {
        if(n <= 1)
            return n;
        
        int prev2 = 0;
        int prev = 1;
        int curr = -1;
        for(int i=2; i<=n; i++)
        {
            curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};