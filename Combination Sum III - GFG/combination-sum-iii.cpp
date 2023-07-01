//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    
    void solve(int index, int sum, int k, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(index == 9){
            if(sum == target && ds.size() == k) ans.push_back(ds);
            return;
        }
        
        
        ds.push_back(arr[index]);
        sum += arr[index];
        solve(index+1, sum, k, target, ans, ds);
        
        ds.pop_back();
        sum -= arr[index];
        solve(index+1, sum, k, target, ans, ds);
    }
    
    vector<vector<int>> combinationSum(int K, int N) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(0, 0, K, N, ans, ds);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends