//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    void solve(int index, vector<int>& arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(index == arr.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(arr[index]);
        solve(index+1, arr, ans, ds);
        
        ds.pop_back();
        
        while(index < arr.size()-1 && arr[index] == arr[index+1]) index++;
        
        solve(index+1, arr, ans, ds);
    }
    
    
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        
        solve(0, nums, ans, ds);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends