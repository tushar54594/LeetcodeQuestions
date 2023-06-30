class Solution {
public:
    int mod = 1e9+7;
    
    long long power(long long a,long long n)
    {
        if(n == 0) return 1;
        if(n == 1) return a%mod;
        
        long long ans = 1;
        long long val = power(a, n/2)%mod;
        
        if(n%2 == 1) ans = (ans*a)%mod;
        
        return (ans*((val*val)%mod))%mod;
    }
    
    int countGoodNumbers(long long n) {
        long long ans = power(20, n/2);
        if(n%2 == 1) ans = (ans*5)%mod;
        
        return ans;
    }
};

/*
even no - 0,2,4,6,8 -> 5
prime no b/w  0 to 9 - 2,3,5,7 -> 4


So for a no of length n, 
Eg n = 4
5 4 5 4
ans will be 20^2

for n , ans = 20^n/2;
if n is odd, only 1 even index is left, so ans = 5 * ans;

for finding 20^n/2 , we use BINARY EXPONENTIATION 
*/