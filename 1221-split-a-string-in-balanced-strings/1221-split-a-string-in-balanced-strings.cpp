class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int balance = 0;
        for(auto a : s)
        {
            if(a == 'L')
                balance++;
            else
                balance--;
            
            if(balance == 0)
                ans++;
        }
        return ans;
    }
};