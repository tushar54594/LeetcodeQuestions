class Solution {
public:
    int dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        int ans = 0;
        for(auto a : adj[node])
        {
            if(!vis[abs(a)])
                ans += dfs(abs(a), adj, vis) + (a > 0); //if a > 0, it means we had to add the reverse edge
        }
        
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n+1];
        for(auto c : connections)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]); 
            //-ve denotes edge was not present we added it to make graph undirectional
        }
        
        vector<int> vis(n, 0);
        return dfs(0, adj, vis);
    }
};