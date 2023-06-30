class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return 1.0*x;
        
        double ans = 1;
        double val;
        
        if(n < 0){
            ans = 1;
            val = myPow(1/x, -(n/2));

            if(-(n%2) == 1) ans = ans*(1/x);

            return ans*val*val;
        }
        
        ans = 1;
        val = myPow(x, n/2);
        
        if(n%2 == 1) ans = ans*x;
        
        return ans*val*val;
    }
};

/*
We have to find a^n
if n is even => a^n = a^n/2 * a^n/2
if n is odd  => a^n = a * a^n/2 * a^n/2

This is known as BINARY EXPONENTIATION
*/