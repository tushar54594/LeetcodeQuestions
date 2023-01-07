class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++)
            pq.push({score[i], i});
        
        vector<string> ans(n);
        int count = 1;
        while(pq.size() > 0)
        {
            auto top = pq.top();
            pq.pop();
            if(count == 1)
                ans[top.second] = "Gold Medal";
            else if(count == 2)
                ans[top.second] = "Silver Medal";
            else if(count == 3)
                ans[top.second] = "Bronze Medal";
            else
                ans[top.second] = to_string(count);
            
            count++;
        }
        return ans;
    }
};