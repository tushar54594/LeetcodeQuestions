class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0; i<n; i++)
        {
            if(manager[i] == -1) continue;
            else adj[manager[i]].push_back(i);
        }
        
        int ans = informTime[headID];
        queue<pair<int,int>> q;
        q.push({headID, ans});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int head = it.first;
            int time = it.second;
            
            for(auto a : adj[head])
            {
                ans = max(ans, time + informTime[a]);
                q.push({a, time + informTime[a]});
            }
        }
        
        return ans;
    }
};