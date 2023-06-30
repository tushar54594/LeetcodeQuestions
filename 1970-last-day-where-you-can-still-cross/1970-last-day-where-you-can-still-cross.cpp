class Solution {
public:
    
    bool DFS(vector<vector<int>> &grid, int i, int j, int row, int col)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] == 1) return false;
        
        if(i == row - 1) return true;
        
        grid[i][j] = 1;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int k = 0; k<4; k++){
            int newr = i + drow[k];
            int newc = j + dcol[k];
            
            if(DFS(grid, newr, newc, row, col)) return true;
        }
        
        return false;
    }
    
    
    bool canCross(vector<vector<int>>& cells, int mid, int row, int col)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        for(int i=0; i<=mid; i++){
            
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            
            grid[x][y] = 1;
        }
        
        for(int j=0; j<col; j++){
            if(grid[0][j] == 0 && DFS(grid, 0, j, row, col)) return true;
        }
        
        return false;
    }
    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0;
        int r = cells.size();
        
        int lastDay = 0;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(canCross(cells, mid, row, col)){
                lastDay = mid + 1;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        return lastDay;
    }
};