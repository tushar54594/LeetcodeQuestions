class Solution {
public:
    int sumOfPrimeFactors(int n)
    {
        int ans = 0;
        for(int i=2; i<=n; i++)
        {
            while(n%i == 0)
            {
                ans += i;
                n /= i;
            }
        }
        return ans;
    }
    
    int smallestValue(int n) {
        while(true)
        {
            int sum = sumOfPrimeFactors(n);
            if(n == sum) break; //this means n is a prime no and we cannot replace further
            else n = sum;
        }
        return n;
    }
};