class Solution {
public:
    int countPrimes(int n) {
        //sieve of eratosthenes
        vector<bool> prime(n+1, true); //n+1 size since from 0 to n we have n+1 numbers
        prime[0] = prime[1] = false;
        for(int i=2; i*i<=n; i++)
        {
            if(prime[i])
            {
                for(int j = i*i; j<=n; j = j+i)
                    prime[j] = false;
            }
        }
        
        //now we count the number of prime numbers
        int count = 0;
        for(int i=2; i<n; i++)
        {
            if(prime[i])
                count++;
        }
        return count;
    }
};