//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool comparator(string a, string b)
	{
	    if(a+b > b + a) return true;
	    
	    return false;
	}
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(), arr.end(), comparator);
	    string ans;
	    for(auto a : arr)
	        ans += a;
	    //remove starting zeroes
	    int i = 0;
	    while(ans[i] == '0' && i < ans.size()-1) i++;
	    
	    ans = ans.substr(i);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends