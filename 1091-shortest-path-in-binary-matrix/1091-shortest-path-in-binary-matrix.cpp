class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        
        queue<pair<int, pair<int,int>>> q; //{distance, {row, col}}
        q.push({1, {0, 0}});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == n-1) return distance;
            
            //for iterating all 8 directions
            for(int drow = -1; drow<=1; drow++)
            {
                for(int dcol = -1; dcol<=1; dcol++)
                {
                    int newr = r + drow;
                    int newc = c + dcol;
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc] == 0)
                    {
                        if(distance + 1 < dist[newr][newc])
                        {
                            dist[newr][newc] = distance + 1;
                            q.push({dist[newr][newc], {newr,newc}});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};

/*
Dijkstra's algo using queue as priority queue is not needed since always there is
a increase of 1 unit distance only so it will be stored in queue in ascending order only

So Dijkstra's algo using queue which is nothing but BFS only
*/