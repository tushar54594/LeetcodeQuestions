class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i=0; i<flowerbed.size() && n>0; i++)
        {
            if(flowerbed[i] == 0)
            {
                int next = (i == flowerbed.size()-1) ? 0 : flowerbed[i+1];
                int prev = (i == 0) ? 0 : flowerbed[i-1];
                if(prev == 0 && next == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        
        if(n == 0)
            return true;
        
        return false;
    }
};