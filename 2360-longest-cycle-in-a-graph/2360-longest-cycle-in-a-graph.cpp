class Solution {
public:
    
    int c = 0;

bool dfs(int src, vector<vector<int>>& adj, vector<int>& v, vector<int>& rs) {
    v[src] = 1;
    rs[src] = 1;
    c += 1;
    for (int i = 0; i < adj[src].size(); i++) {
        int neigh = adj[src][i];
        if (v[neigh] == 0) {
            if (dfs(neigh, adj, v, rs))
                return true;
        } else if (rs[neigh] == 1)
            return true;
    }
    rs[src] = 0;
    c -= 1;
    return false;
}
    
    int longestCycle(vector<int>& a) {
        int n = a.size();
    vector<int> v(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        adj[i] = vector<int>();
    for (int i = 0; i < n; i++)
        if (a[i] != -1)
            adj[a[i]].push_back(i);
    vector<int> rs(n, 0);
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            bool x = dfs(i, adj, v, rs);
            if (x == true) {
                cout << c << endl;
                // int sum = 0;
                // for(int j = 0; j < nodes.size(); j++)
                //     sum += nodes[j];
                ans = max(ans, c);
                c = 0;
            }
        }
    }
    return ans;
    }
};