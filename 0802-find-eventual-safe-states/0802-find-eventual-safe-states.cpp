class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> graphRev[n];
        vector<int> indegree(n, 0);
        
        //Reverse Edges of graph
        for(int i=0; i<n; i++)
        {
            for(auto b : graph[i])
            {
                graphRev[b].push_back(i);
                indegree[i]++;
            }
        }
            
        //Topo sort
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto a : graphRev[node])
            {
                indegree[a]--;
                if(indegree[a] == 0) q.push(a);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
1. Reverse the graph
The inttution behind making the reverse graph is to make indgree 0 for terminal nodes which will definitely be safe. stating node with indgree 0 may or may not lead to terminal node,they can lead to cycle. hence we have reversed the graph to play safe by making indgree of termial node 0 and reversing the graph

2. Anyone with indegree 0 will be terminal node and use queue to solve topo sort normally
*/