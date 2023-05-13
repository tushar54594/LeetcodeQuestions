//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
                /*
                No need of inserting reverse again as it will be ignored by our data structure
                */
            }
        }
        
        DisjointSet ds(V);
        
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for(auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            //check if they belong to the same component then no need to take it in MST
            if(ds.findUPar(u) != ds.findUPar(v)) 
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends