class Solution {
public:
    int product(int n)
    {
        int p = 1;
        while(n>0)
        {
            int digit = n%10;
            p *= digit;
            n = n/10;
        }
        return p;
    }
    
    int sum(int n)
    {
        int s = 0;
        while(n>0)
        {
            int digit = n%10;
            s += digit;
            n = n/10;
        }
        return s;
    }
    
    int subtractProductAndSum(int n) {
        int p = product(n);
        int s = sum(n);
        return p-s;
    }
};