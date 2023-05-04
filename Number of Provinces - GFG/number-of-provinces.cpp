//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis)
    {
        vis[node] = 1;
        for(auto a : adjLs[node])
        {
            if(!vis[a]) dfs(a, adjLs, vis);
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        int n = V;
        vector<int> adjLs[n];
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(adj[i][j] == 1 && i != j) adjLs[i].push_back(j);
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends