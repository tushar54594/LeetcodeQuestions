//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        set<pair<int, int>> s;
        s.insert({0, S});
        
        while(!s.empty())
        {
            auto it = *(s.begin());
            int node = it.second;
            int distance = it.first;
            s.erase(it);
            
            for(auto a : adj[node])
            {
                int edgeWeight = a[1];
                int adjNode = a[0];
                
                if(distance + edgeWeight < dist[adjNode])
                {
                    //erase if it already existed in set
                    if(dist[adjNode] != 1e9) s.erase({dist[adjNode], adjNode});
                    
                    dist[adjNode] = distance + edgeWeight;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
    
    /*
    1. set will erase the already existing path which we do not do in pq
    But we cannot say that it is better than pq
    It depends on the graph
    
    **Incase of PQ, the maximum heap size can go upto E = number of edges, leading to 
       complexity = O(E*logE).
    **Incase of set, the maximum set size can go upto V =. number of vertices, leading 
       to complexity = O(E*logV).
    */
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends