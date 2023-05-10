//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        
        queue<pair<int, pair<int,int>>> q; //{distance, {row, col}}
        q.push({0, {source.first, source.second}});
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == destination.first && c == destination.second) return distance;
            
            for(int i=0; i<4; i++)
            {
                int newr = r + drow[i];
                int newc = c + dcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc] == 1)
                {
                    if(distance + 1 < dist[newr][newc])
                    {
                        dist[newr][newc] = distance + 1;
                        q.push({dist[newr][newc], {newr,newc}});
                    }
                }
            }
        }
        
        return -1;
        
    }
    
    /*
    Dijkstra's algo using queue as priority queue is not needed since always there is
    a increase of 1 unit distance only so it will be stored in queue in ascending order only
    
    So Dijkstra's algo using queue which is nothing but BFS also
    */
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends