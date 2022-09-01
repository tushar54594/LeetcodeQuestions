class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int j=0; j<m; j++)
        {
            vector<int> v;
            for(int i=n-1; i>=0; i--)
            {
                v.push_back(matrix[i][j]);
            }
            ans.push_back(v);
        }
        
        matrix = ans;
    }
};