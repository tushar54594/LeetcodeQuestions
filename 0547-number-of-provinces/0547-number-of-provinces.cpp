class Solution {
public:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis)
    {
        vis[node] = 1;
        for(auto a : adjLs[node])
        {
            if(!vis[a])
                dfs(a, adjLs, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        //create the adjacency list
        vector<int> adjLs[n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, adjLs, vis);
                ans++;
            }
        }
        
        return ans;
    }
};