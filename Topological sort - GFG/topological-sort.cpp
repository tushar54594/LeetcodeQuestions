//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++)
	    {
	        for(auto a : adj[i]) indegree[a]++;
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++)
	    {
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        
	        for(auto a : adj[node])
	        {
	            indegree[a]--;
	            if(indegree[a] == 0) q.push(a);
	        }
	    }
	    
	    return topo;
	}
	
	/*
	Using BFS
	1. Find indegree for all the nodes
	2. Insert all nodes with indegree 0 into the queue
	3. Take them out of the queue and reduce the indegree of their adjacent nodes by 1
	4. If indegree becomes zero again put them in the queue
	*/
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends