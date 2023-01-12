class Solution {
public:
    void countSort(vector<vector<int>>& mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        int i = r;
        int j = c;
        
        vector<int> v(101);
        while(i<m && j<n)
        {
            v[mat[i][j]]++;
            i++;
            j++;  //next element of diagonal will be at i++ and j++
        }
        
        i = r;
        j = c;
        for(int k=1; k<v.size(); k++)
        {
            while(v[k] > 0)
            {
                mat[i][j] = k;
                v[k]--;
                i++;
                j++;
            }
        }
        
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i=0; i<m; i++)
            countSort(mat, i, 0);
        
        for(int j=1; j<n; j++)
            countSort(mat, 0, j);
        
        return mat;
    }
};