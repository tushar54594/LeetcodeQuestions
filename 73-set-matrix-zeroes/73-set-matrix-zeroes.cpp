class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool row = false, col = false;
        
        //check if 0 is present in the 1st column
        for(int i=0; i<n; i++)
        {
            if(matrix[i][0] == 0)
                col = true;
        }
        
        //check if 0 is present in the 1st row
        for(int j=0; j<m; j++)
        {
            if(matrix[0][j] == 0)
                row = true;
        }
        
        //check for zeros for the rest of the matrix
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //make the required rows 0
        for(int i=1; i<n; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j=0; j<m; j++)
                    matrix[i][j] = 0;
            }
        }
        
        //make the required columns 0
        for(int j=1; j<m; j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i=0; i<n; i++)
                    matrix[i][j] = 0;
            }
        }
        
        //check for 1st row if it had 0 present originally
        if(row)
        {
            for(int j=0; j<m; j++)
                matrix[0][j] = 0;
        }
        
        //check for 1st col if it had 0 present originally
        if(col)
        {
            for(int i=0; i<n; i++)
                matrix[i][0] = 0;
        }
    }
};