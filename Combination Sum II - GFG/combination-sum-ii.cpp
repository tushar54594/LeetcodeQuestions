//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(index == arr.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        
        if(arr[index] <= target){
            ds.push_back(arr[index]);
            solve(index+1, target - arr[index], arr, ans, ds);
            ds.pop_back();
        }
        
        while(index < arr.size()-1 && arr[index] == arr[index+1]) index++;
        solve(index+1, target, arr, ans, ds);
    }
    
    
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        
        solve(0, target, candidates, ans, ds);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends