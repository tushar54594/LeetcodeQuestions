class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto a : edges)
        {
            dist[a[0]][a[1]] = a[2];
            dist[a[1]][a[0]] = a[2];
        }
        
        for(int i=0; i<n; i++) dist[i][i] = 0;
        
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int countCity = n;
        int cityNo = -1;
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(dist[i][j] <= distanceThreshold) count++;
            }
            
            if(count <= countCity)
            {
                countCity = count;
                cityNo = i;
            }
        }
        return cityNo;
    }
};

//FLOYD WARSHALL ALGORITHM