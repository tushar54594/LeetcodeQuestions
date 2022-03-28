class Solution {
public:
    int mySqrt(int x) {
        long l = 0;
        long h = x;
        while(l<=h){
            long mid = l + (h-l)/2;
            if(mid*mid <= x)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return h;
    }
};