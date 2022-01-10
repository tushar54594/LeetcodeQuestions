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

// Staircase Search Algorithm
// Start with element at i = 0 and j = n-1 and it can go till element at i = m-1 and j = 0 where m= number of rows and n = number of columns