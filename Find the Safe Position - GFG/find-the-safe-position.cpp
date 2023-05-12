//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int> &v, int k, int index)
    {
        if(v.size() == 1) return v[0];
        
        index = (index + k)%v.size();  //jo banda marne wala hai uska index
        v.erase(v.begin() + index);
        
        return solve(v, k, index);
    }
    
    int safePos(int n, int k) {
        vector<int> arr;
        for(int i=1; i<=n; i++) arr.push_back(i);
        
        k = k-1; //since 0 based indexing
        int index = 0;
        return solve(arr, k, index);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends