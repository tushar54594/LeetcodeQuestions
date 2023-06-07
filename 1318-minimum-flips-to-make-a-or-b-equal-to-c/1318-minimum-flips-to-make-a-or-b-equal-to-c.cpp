class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x,y,z;
        int ans = 0;
        
        for(int i=0; i<32; i++)
        {
            x = a & (1<<i);
            y = b & (1<<i);
            z = c & (1<<i);
            
            if(z == 0 && x != 0 && y == 0) ans += 1;
            else if(z == 0 && x == 0 && y != 0) ans += 1;
            else if(z == 0 && x != 0 && y != 0) ans += 2;
            else if(z != 0 && x == 0 && y == 0) ans += 1;
        }
        
        return ans;
    }
};