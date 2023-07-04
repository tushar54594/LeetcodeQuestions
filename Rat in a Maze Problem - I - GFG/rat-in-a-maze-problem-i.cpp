//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, 
    vector<vector<int>> &visited, int di[], int dj[])
    {
        if(i == n-1 && j == n-1)
        {
            ans.push_back(move);
            return;
        }
        
        //DLRU (Since we have to print in lexicographically increasing order)
        //For every case, we have to check 3 conditions:
        //1. The next index should be inside the boundary
        //2. The cell should not be visited
        //3. The cell should have a 1
        
        string dir = "DLRU";
        for(int k=0; k<4; k++){
            int newi = i + di[k];
            int newj = j + dj[k];
            if(newi>=0 && newi<n && newj>=0 && newj<n && !visited[newi][newj]
            && a[newi][newj] == 1){
                visited[i][j] = 1;
                solve(newi, newj, a, n, ans, move + dir[k], visited, di, dj);
                visited[i][j] = 0;
            }
        }
    
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n,0));
        
        int di[4] = {1,0,0,-1};
        int dj[4] = {0,-1,1,0};  //DLRU 
        
        if(m[0][0] == 1)
            solve(0,0,m,n,ans,"",visited, di, dj);
            
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends