class Solution {
public:
    int sumOfDigits(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int digit = n%10;
            sum += digit;
            n /= 10;
        }
        return sum;
    }
    
    int addDigits(int num) {
        while(num > 9)
        {
            num = sumOfDigits(num);
        }
        
        return num;
    }
};