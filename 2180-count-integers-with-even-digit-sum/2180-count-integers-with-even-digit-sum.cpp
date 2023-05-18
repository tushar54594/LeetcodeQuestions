class Solution {
public:
    int sum(int n)
    {
        int ans = 0;
        while(n > 0)
        {
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    
    int countEven(int num) {
        int c = 0;
        for(int i=1; i<=num; i++)
        {
            int s = sum(i);
            if(s%2 == 0) c++;
        }
        
        return c;
    }
};