class Solution {
public:
    //to find sum of squares of digits of a number
    int helper(int n)
    {
        int ans = 0;
        while(n > 0)
        {
            int digit = n%10;
            ans += digit*digit;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        //either the number will end with 1 or there will be a cycle i.e. the number will appear again and this process will continue
        //Therefore we will use the floyd's cycle detection algorithm 
        
        int slow = n, fast = n;
        do
        {
            slow = helper(slow);
            fast = helper(helper(fast));
        }while(slow != fast);
        
        return slow == 1;
    }
};