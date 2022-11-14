class Solution {
public:
    bool checkPerfectNumber(int num) {
        //Please note for every divisor i, there exists another divisor, num/i. Example, if num = 14, and i = 2, then           num/i = 7 is also a divisor. So we can limit our search to sqrt(num) values only.
        //If at any point we come across a perfect square then i == num/i, but we need to add this to our sum only once,          hence the condition.
        if(num < 2)
            return false;
        
        int sum = 1;
        for(int i=2; i<=sqrt(num); i++)
        {
            if(num%i == 0)
                sum += (i == num/i) ? i : i + num/i;
            if(sum > num)
                return false;
        }
        
        return sum == num;
    }
};