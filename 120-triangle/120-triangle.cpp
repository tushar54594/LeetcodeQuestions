class Solution {
public: 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, -1);
        
        //base case (Try to think the possible values of j)
        for(int j=0; j<n; j++)
        {
            front[j] = triangle[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            vector<int> curr(n, -1);
            for(int j=i; j>=0; j--)
            {
                int v1 = triangle[i][j] + front[j];
                int v2 = triangle[i][j] + front[j+1];
                curr[j] = min(v1, v2);
            }
            front = curr;
        }
        return front[0];
    }
};