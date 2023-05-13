class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto a : times)
        {
            adj[a[0]].push_back({a[1], a[2]});
        }
        
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int distance = it.first;
            int node = it.second;
            
            for(auto a : adj[node])
            {
                int edgeWeight = a.second;
                int adjNode = a.first;
                
                if(distance + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        for(int i=1; i<=n; i++)
        {
            if(dist[i] == 1e9) return -1;
        }
        
        int maxi = 0;
        for(int i=1; i<=n; i++) maxi = max(maxi, dist[i]);
        
        return maxi;
    }
};