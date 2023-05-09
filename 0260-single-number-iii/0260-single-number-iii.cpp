class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_val = 0;
        for(auto a : nums) xor_val ^= a;
        
        int n = 1;
        while(1) {
            if((n & xor_val) == 0) {
                n = n << 1;
            }
            else break;
        }
        
        int x = 0;
        int y = 0;
        for(auto a : nums)
        {
            if(a & n) x ^= a;
            else y ^= a;
        }
        
        return {x, y};
    }
};