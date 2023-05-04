//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>> q; //{{r,c}, distance}
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({{i, j}, 0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	    
	    int drow[] = {-1,1,0,0};
	    int dcol[] = {0,0,1,-1};
	    
	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int distance = q.front().second;
	        q.pop();
	        
	        ans[r][c] = distance;
	        
	        for(int i=0; i<4; i++)
	        {
	            int nrow = r + drow[i];
	            int ncol = c + dcol[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
	            {
	                q.push({{nrow, ncol}, distance+1});
	                vis[nrow][ncol] = 1;
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends