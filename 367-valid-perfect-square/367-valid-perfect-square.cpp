class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0;
        int h = num;
        while(l<=h){
            long mid = l + (h-l)/2;
            if(mid*mid > num)
                h = mid - 1;
            else
                l = mid + 1;
        }
        if(h*h == num)
            return true;
        else
            return false;
    }
};