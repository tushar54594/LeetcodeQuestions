class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i=0; i<9; i++){
            
            if(i != row && board[i][col] == c) return false;  //row
             
            if(i != col && board[row][i] == c) return false;  //col
            
            if(row != (3*(row/3) + i/3) && col != (3*(col/3) + i%3) && board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;  //3x3 sub-box
        }
        
        return true;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                
                if(board[i][j] != '.'){
                    
                    if(isValid(board, i, j, board[i][j]) == false) return false;
                }
            }
        }
        
        return true;
    }
};