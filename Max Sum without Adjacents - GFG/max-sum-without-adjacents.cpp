//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int solve(int i, int *arr, vector<int> &dp)
    {
        if(i == 0) return arr[0];
        if(i< 0) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int pick = arr[i] + solve(i-2, arr, dp);
        int notPick = 0 + solve(i-1, arr, dp);
        
        return dp[i] = max(pick, notPick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, -1);
	    return solve(n-1, arr, dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends