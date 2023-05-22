class DisjointSet {
public:
    vector<int> parent, size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        //step1
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) continue;
                
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,1,0,-1};
                
                for(int k=0; k<4; k++)
                {
                    int newr = i + drow[k];
                    int newc = j + dcol[k];
                    
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc] == 1)
                    {
                        int nodeNo = i*n + j;
                        int adjNodeNo = newr*n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        
        //step2 - 0 ko 1 bana
        int maxi = -1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1) continue;
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,1,0,-1};
                
                set<int> components;
                for(int k=0; k<4; k++)
                {
                    int newr = i + drow[k];
                    int newc = j + dcol[k];
                    
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc] == 1)
                    {
                        components.insert(ds.findUPar(newr*n + newc));
                    }
                }
                
                int sizeTotal = 0;
                for(auto a : components) sizeTotal += ds.size[a];
                
                maxi = max(maxi, sizeTotal + 1);
            }
        }
        
        //if all are 1's
        if(maxi == -1) return n*n;
        
        return maxi;
    }
};