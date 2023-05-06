class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(auto a : prerequisites)
        {
            adj[a[1]].push_back(a[0]);
        }
        
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++)
        {
            for(auto a : adj[i])
            {
                indegree[a]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto a : adj[node])
            {
                indegree[a]--;
                if(indegree[a] == 0) q.push(a);
            }
        }
        
        if(topo.size() == n) return topo;
        
        return {};
    }
};