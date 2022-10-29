class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int n = obstacleGrid.size();
        int m= obstacleGrid[0].size();
        
      vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
            if(i==0 && j==0 && obstacleGrid[i][j] == 0){
                    dp[0][0] = 1;
            }
            else if(obstacleGrid[i][j] == 1){
                   dp[i][j] = 0;
                }
        else{
        
        
                int top=0;
                int left=0;
                
             if(i>0){   
        top = dp[i-1][j];
             }
                if(j>0){
         left = dp[i][j-1];
                }
        
         dp[i][j] =  top+left;
        }
    } 
            }
        
        return dp[n-1][m-1];
    }
};