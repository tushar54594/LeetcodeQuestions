//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        //Do relaxation N-1 times
        for(int i=0; i<V-1; i++)
        {
            for(auto a : edges)
            {
                int u = a[0];
                int v = a[1];
                int wt = a[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        
        //kth relaxation to check if -ve cycle exits or not
        for(auto a : edges)
        {
            int u = a[0];
            int v = a[1];
            int wt = a[2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                return {-1};
        }
        
        return dist;
    }
    
    /*
    According to our intuition, we should have minimized all the distances within N-1 iterations
    (that means, after N-1 iterations no relaxation of edges is possible). 
    
    In order to check the existence of a negative cycle, we will relax the edges one more time 
    after the completion of N-1 iterations. And if in that Nth iteration, it is found that 
    further relaxation of any edge is possible, we can conclude that the graph has a negative 
    cycle. Thus, the Bellman-Ford algorithm detects negative cycles.
    */
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends