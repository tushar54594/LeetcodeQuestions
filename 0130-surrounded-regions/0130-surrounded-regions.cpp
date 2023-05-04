class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1 || board[i][j] == 'X') 
            return;
        
        vis[i][j] = 1;
        
        dfs(i-1, j, vis, board);
        dfs(i+1, j, vis, board);
        dfs(i, j-1, vis, board);
        dfs(i, j+1, vis, board);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //traverse on 1st row, 1st col, last row, last col
        
        //traverse first row and last row
        for(int j=0; j<m; j++)
        {
            //first row
            if(!vis[0][j] && board[0][j] == 'O') dfs(0, j, vis, board);
            //last row
            if(!vis[n-1][j] && board[n-1][j] == 'O') dfs(n-1, j, vis, board);
        }
        
        //traverse first col and last col
        for(int i=0; i<n; i++)
        {
            //first col
            if(!vis[i][0] && board[i][0] == 'O') dfs(i, 0, vis, board);
            //last col
            if(!vis[i][m-1] && board[i][m-1] == 'O') dfs(i, m-1, vis, board);    
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

/*
Apply DFS
Start from the boundary O's & mark them that they will not be converted & convert the remaining O's
*/