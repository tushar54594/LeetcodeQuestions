class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        //{r,c},time
        queue<pair<pair<int,int>, int>> q;
        int vis[n][m];
        int cntFresh = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                else
                    vis[i][j] = 0;
                
                if(grid[i][j] == 1)
                    cntFresh++;
            }
        }
        
        //for traversing 4 neighbours
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        int cnt = 0;
        int time = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            time = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, time+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        
        if(cnt != cntFresh) return -1;
        
        return time;
    }
};

//BFS will take minimum time as it traverses level wise
//It is multisource bfs thus we are storing the index of rotten orange(i.e. starting point) in a queue