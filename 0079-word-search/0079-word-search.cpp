class Solution {
public:
    bool search(int index, int i, int j, vector<vector<char>>& board, string word, int m, int n)
    {
        if(index == word.size()) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;
        
        bool ans = false;
        if(word[index] == board[i][j]){
            board[i][j] = '*';
            ans = search(index+1, i+1, j, board, word, m, n) || search(index+1, i-1, j, board, word, m, n) || search(index+1, i, j-1, board, word, m, n) || search(index+1, i, j+1, board, word, m, n);
            
            board[i][j] = word[index];
        }
        
        return ans;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(word[0] == board[i][j])
                {
                    if(search(0, i, j, board, word, m, n)) return true;
                }
                
            }
        }
        
        return false;
    }
};