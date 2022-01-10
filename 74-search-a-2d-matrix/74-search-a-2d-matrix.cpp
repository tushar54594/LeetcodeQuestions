class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = n-1;
    while(i<=m-1 and j>=0){
        if(target == matrix[i][j])
            return true;
        else if(target < matrix[i][j])
            j--;
        else if(target > matrix[i][j])
            i++;
    }
    return false;
  }
};