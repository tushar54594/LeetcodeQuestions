class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto a : amount){
            if(a > 0) pq.push(a);
        }
        
        int ans = 0;
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            ans++;
            a--;
            b--;
            if(a > 0) pq.push(a);
            if(b > 0) pq.push(b);
        }
        
        if(pq.size() == 1) ans += pq.top();
        return ans;
    }
};