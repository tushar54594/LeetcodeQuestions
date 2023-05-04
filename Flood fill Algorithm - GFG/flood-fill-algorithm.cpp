//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int initialColor, int newColor)
    {    
        int n = image.size();
        int m = image[0].size();
         
        if(i<0 || i>=n || j<0 || j>=m || image[i][j] != initialColor || image[i][j] == newColor)
            return;
            
        image[i][j] = newColor;
        dfs(i-1, j, image, initialColor, newColor);
        dfs(i+1, j, image, initialColor, newColor);
        dfs(i, j+1, image, initialColor, newColor);
        dfs(i, j-1, image, initialColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int n = image.size();
         int m = image[0].size();
         
         int initialColor = image[sr][sc];
         
         dfs(sr, sc, image, initialColor, newColor);
         
         return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends