class Solution {
public:
    bool helper(int node, vector<int> &color, vector<vector<int>>& graph, int n)
    {
        queue<int> q;
        q.push(node);
        color[node] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto a : graph[node])
            {
                //if adjacent node is yet not coloured
                //we will give the opposite color
                if(color[a] == -1)
                {
                    color[a] = !color[node];
                    q.push(a);
                }
                //is the adjacent node having the same color
                else if(color[a] == color[node]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(helper(i, color, graph, n) == false) return false;
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