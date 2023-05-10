class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int, pair<int,int>>, 
        vector<pair<int, pair<int,int>>>, 
        greater<pair<int, pair<int,int>>>> pq;
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});  //{effort, {row, col}}
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1) return effort;  //ans
            
            for(int i=0; i<4; i++)
            {
                int newr = r + drow[i];
                int newc = c + dcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    int diff = abs(heights[newr][newc] - heights[r][c]);
                    int newEffort = max(effort, diff);
                    if(newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({dist[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        
        return 0;
    }
};

/*
You can also do without early returning ie at the end simply dist[n-1][m-1]. Priority queue/set gives smallest value on top, if that smallest value is destination then that has to be the ans because, you cannot further reduce the value by using other bigger values present in the DS
*/