class Solution {
public:
    vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = 1e9;
        
        dist[S] = 0;
        pq.push({0, S}); //{dist, source}
        
        while(!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto a : adj[node])
            {
                int adjNode = a.first;
                int edgeWeight = a.second;
                
                if(distance + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(auto a : edges)
        {
            adj[a[0]].push_back({a[1], a[2]});
            adj[a[1]].push_back({a[0], a[2]});
        }
        
        int countCity = n;
        int cityNo = -1;
        
        for(int i=0; i<n; i++)
        {
            int cnt = 0;
            vector<int> v = dijkstra(n, adj, i);
            for(auto a : v)
            {
                if(a <= distanceThreshold) cnt++;
            }
            
            if(cnt <= countCity)
            {
                countCity = cnt;
                cityNo = i;
            }
        }
        
        return cityNo;
    }
};

/*
Using Dijkstra's algo
Compute Dijkstra for every node since Dijkstra is single source shortest path
*/