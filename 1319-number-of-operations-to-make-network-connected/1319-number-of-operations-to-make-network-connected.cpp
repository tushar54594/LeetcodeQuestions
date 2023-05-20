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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        
        int cntExtraEdges = 0;
        for(int i=0; i<connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            //extra
            if(ds.findUPar(u) == ds.findUPar(v)) cntExtraEdges++;
            else ds.unionBySize(u, v);
        }
        
        int connectedComp = 0;
        for(int i=0; i<n; i++)
        {
            if(ds.findUPar(i) == i) connectedComp++;
        }
        
        int ans = connectedComp-1;
        if(cntExtraEdges >= ans) return ans;
        
        return -1;
    }
};

/*
Find n = no of connected components
Then ans will be n-1;
since to connect n components, we require n-1 edges

But we have a remove an edge from a component and attach it to the other component
We can only remove the extra edges such that graph will remain connected even if we remove that edges

Thus
ans = n-1;
if(extraedges >= ans) return ans;
else return -1;
*/