class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while(target != 1)
        {
            if(target%2 == 0)
            {
                if(maxDoubles>0)
                {
                    target /= 2;
                    count++;
                    maxDoubles--;
                }
                else
                {
                    return count += target-1;
                }
            }
            else
            {
                target -= 1;
                count++;
            }
        }
        return count;
    }
};