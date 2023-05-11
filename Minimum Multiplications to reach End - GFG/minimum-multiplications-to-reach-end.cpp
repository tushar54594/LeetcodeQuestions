//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> vis(100000, 0);
        vis[start] = 1;
        
        queue<pair<int,int>> q; //{steps, node}
        q.push({0, start});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int steps = it.first;
            int node = it.second;
            
            if(node == end) return steps;
            
            for(auto a : arr)
            {
                int x = (node*a)%100000;
                if(!vis[x])
                {
                    q.push({steps+1, x});
                    vis[x] = 1;
                }
            }
        }
        return -1;
    }
    
    /*
    the nodes will be from 0,1,2 ... , 9999 since we do modulo 100000
    */
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends