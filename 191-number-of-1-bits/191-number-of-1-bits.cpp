class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n>0){
            int lastdigit = n&1;
            count = count + lastdigit;
            n = n>>1;
        }
        return count;
    }
};