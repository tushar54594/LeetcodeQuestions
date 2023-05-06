class Solution {
public:
    bool dfs(int node, vector<int> &color, vector<vector<int>>& graph, int c)
    {
        color[node] = c;
        
        for(auto a : graph[node])
        {
            if(color[a] == -1) 
            {
                if(dfs(a, color, graph, !c) == false) return false;
            }
            else if(color[a] == c) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
	    for(int i=0; i<V; i++)
	    {
	        if(color[i] == -1)
	        {
	            if(dfs(i, color, graph, 0) == false) return false;
	        }
	    }
	    
	    return true;
    }
};

//Bipartite graph : A graph that can be colored with 2 colors such that no 2 adjacent nodes have the same color

/*
If there is no cycle in graph => bipartite 
If cycle length is even => bipartite
If cycle length is odd => NOT a bipartite
*/