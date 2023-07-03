class Solution {
public:
    int solve(int col, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
        if(col == n){
            return 1;
        }
        
        int ans = 0;
        for(int row = 0; row <n; row++){
            if(leftRow[row] == 0 && upperDiagonal[row+col] == 0 && lowerDiagonal[n-1+col-row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[n-1 + col - row] = 1;
                
                ans += solve(col+1, board, leftRow, upperDiagonal, lowerDiagonal, n);
                
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[n-1 + col - row] = 0;
            }
        }
        
        return ans;
    }
    
    
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0; i<n; i++) board[i] = s;
        
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);
        
        return solve(0, board, leftRow, upperDiagonal, lowerDiagonal, n);
    }
};