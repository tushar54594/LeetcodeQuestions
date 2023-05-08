//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
     {
         vis[node] = 1;
         for(auto a : adj[node])
         {
             int v = a.first;
             if(!vis[v]) topoSort(v, adj, vis, st);
         }
         
         st.push(node);
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        //find the topo sort
        vector<int> vis(N, 0);
        stack<int> st;
        for(int i=0; i<N; i++)
        {
            if(!vis[i]) 
                topoSort(i, adj, vis, st);
        }
        
        //relax the edges(do the distance thing)
        vector<int> dist(N);
        for(int i=0; i<N; i++) dist[i] = 1e9; //mark all as infinity
        
        //source node distance is always zero
        dist[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto a : adj[node])
            {
                int v = a.first;
                int wt = a.second;
                
                if(dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i=0; i<N; i++)
        {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
    
    /*
    1. Do a topo sort on the graph and store in the stack
    2. Take nodes out of stack one by one and relax the edges
    
    WHY TOPOSORT?
    We moved sequentially i.e. the nodes which are reachable first, we moved there
    Thus we minimized the no of steps (N + M)
    
    Finding the shortest path to a vertex is easy if you already know the shortest paths to all 
    the vertices that can precede it. Processing the vertices in topological order ensures that 
    by the time you get to a vertex, you’ve already processed all the vertices that can precede 
    it which reduces the computation time significantly. In this approach, we traverse 
    the nodes sequentially according to their reachability from the source.

    Dijkstra’s algorithm is necessary for graphs that can contain cycles because they can’t be topologically sorted. In other cases, the topological sort would work fine as we start from the first node, and then move on to the others in a directed manner.
    */
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends