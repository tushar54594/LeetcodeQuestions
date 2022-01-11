class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x>0 or y>0){
            int d1 = x&1;
            int d2 = y&1;
            if(d1 != d2)
                count++;
            x = x>>1;
            y = y>>1;
                        
        }
        return count;
    }
};