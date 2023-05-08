//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0; i<M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> dist(N, -1);
        
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto a : adj[node])
            {
                if(dist[a] == -1)
                {
                    dist[a] = dist[node] + 1;
                    q.push(a); 
                }
            }
        }
        
        
        return dist;
    }
    
    /*
    for unweighted graphs the first time when we reach the target node, that should be the
    shortest distance as we are doing bfs 
    So if a node is not visited, then update the dist of the node by adding +1 to the 
    previous node And if it is visited, then we already got the shortest distance
    */
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends