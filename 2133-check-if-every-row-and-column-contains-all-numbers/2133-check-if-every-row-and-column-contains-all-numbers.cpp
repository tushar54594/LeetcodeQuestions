class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //for row
        for(int i=0; i<n; i++)
        {
            set<int> s;
            for(int j=0; j<n; j++)
            {
                s.insert(matrix[i][j]);
            }
            if(s.size() != n) return false;
        }
        
        //for col
        for(int i=0; i<n; i++)
        {
            set<int> s1;
            for(int j=0; j<n; j++)
            {
                s1.insert(matrix[j][i]);
            }
            if(s1.size() != n) return false;
        }
        
        return true;
    }
};