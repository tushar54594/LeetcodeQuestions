class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int remaining = n;
        int differenceBetweenElements = 1;
        bool left = true;
        
        while(remaining != 1)
        {
            if(left || (remaining%2 == 1)) head += differenceBetweenElements;
            
            differenceBetweenElements *= 2;
            remaining /= 2;
            
            left = !left;
        }
        
        return head;
    }
};

/*
After every operation:
* size will be n/2
* difference b/w elements will be doubled
* head will be initially at 1
* head will change when --> (we iterate from left) OR (we iterate from right && n is odd)
  and it will become head = head + diff;
*/