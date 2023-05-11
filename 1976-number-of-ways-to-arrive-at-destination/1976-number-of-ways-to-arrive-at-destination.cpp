class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<pair<int,int>> adj[n];
        for(auto a : roads)
        {
            adj[a[0]].push_back({a[1], a[2]});
            adj[a[1]].push_back({a[0], a[2]});
        }
        
        vector<long long int> dist(n, 1e18);
        dist[0] = 0;
        
        vector<long long int> ways(n, 0);
        ways[0] = 1;
        
        priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>>> pq;
        pq.push({0, 0});  //{time, node}
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            long long int time = it.first;
            long long int node = it.second;
            
            for(auto a : adj[node])
            {
                long long int adjNode = a.first;
                long long int edgeWeight = a.second;
                
                if(time + edgeWeight == dist[adjNode])
                {
                    ways[adjNode]  = (ways[adjNode] + ways[node])%mod;
                }
                else if(time + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = time + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
            }
        }
        
        return ways[n-1];
    }
};