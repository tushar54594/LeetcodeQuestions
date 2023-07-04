class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i=0; i<9; i++){
            
            if(board[i][col] == c) return false;  //row
             
            if(board[row][i] == c) return false;  //col
            
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;  //3x3 sub-box
        }
        
        return true;
    }
    
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                
                if(board[i][j] == '.')
                {
                    
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            
                            board[i][j] = c;
                            
                            if(solve(board) == true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
};