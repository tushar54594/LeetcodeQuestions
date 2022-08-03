class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int i=0; i<stones.size(); i++)
        {
            pq.push(stones[i]);
        }
        
        while(pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            if(x == y)
            {
                continue;
            }
            else
            {
                int val = y-x;
                pq.push(val);
            }
        }
        
        //now pq can have either 1 element or 0 element
        if(pq.size() == 0)   //consider the test case [2,2]
            return 0;
        else
            return pq.top();
    }
};