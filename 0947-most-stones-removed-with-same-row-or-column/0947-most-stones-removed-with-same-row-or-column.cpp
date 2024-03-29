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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        int maxRow = 0;
        int maxCol = 0;
        //to find dimensions of grid
        for(auto a : stones)
        {
            maxRow = max(maxRow, a[0]);
            maxCol = max(maxCol, a[1]);
        }
        
        //treat every row amd col as a node
        DisjointSet ds(maxRow + maxCol + 1);
        
        unordered_map<int,int> stoneNodes;
        //same row and same col get combined
        for(auto it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        // to identify valid parents we do 
        int cnt = 0;
        for(auto it : stoneNodes)
        {
            if(ds.findUPar(it.first) == it.first) cnt++;
        }
        
        return n - cnt;
    }
};