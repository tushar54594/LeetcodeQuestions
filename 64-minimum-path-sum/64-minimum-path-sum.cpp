class Solution {
    public:
    
    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& ans){
        

        
        if(i==0 && j==0){
            return grid[i][j];
        }
        
        
        if(i<0 || j<0){
            return 1e9;
        }
        
        if(ans[i][j]!=-1){
            return ans[i][j];
        }
        
        int up = grid[i][j] + fun(i-1,j,grid,ans);
        int left = grid[i][j] + fun(i,j-1,grid,ans);
        
        return ans[i][j] = min(up,left);
        
        
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,-1));
        
        return fun(n-1,m-1,grid,ans);
        
        
    }
};