class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>& image, int n, int m, int initialColor, int color)
    {
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1 || image[i][j] != initialColor || image[i][j] == color) 
            return;
        
        vis[i][j] = 1;
        image[i][j] = color;
        
        dfs(i-1, j, vis, image, n, m,initialColor, color);
        dfs(i+1, j, vis, image, n, m,initialColor, color);
        dfs(i, j+1, vis, image, n, m,initialColor, color);
        dfs(i, j-1, vis, image, n, m,initialColor, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int initialColor = image[sr][sc];
        dfs(sr, sc, vis, image, n, m, initialColor, color);
        
        return image;
    }
};