//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto a : adj[node])
        {
            if(!vis[a])
            {
                if(dfs(a, vis, pathVis, adj) == true) return true;
            }
            else if(vis[a] && pathVis[a]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, vis, pathVis, adj) == true) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends