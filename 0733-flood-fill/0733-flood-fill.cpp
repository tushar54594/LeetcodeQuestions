class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int n, int m, int initialColor, int color)
    {
        if(i<0 || i>=n || j<0 || j>=m || image[i][j] != initialColor || image[i][j] == color) 
            return;
        
        image[i][j] = color;
        
        dfs(i-1, j, image, n, m,initialColor, color);
        dfs(i+1, j, image, n, m,initialColor, color);
        dfs(i, j+1, image, n, m,initialColor, color);
        dfs(i, j-1, image, n, m,initialColor, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int initialColor = image[sr][sc];
        dfs(sr, sc, image, n, m, initialColor, color);
        return image;
    }
};