//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int numberOfTriangles(vector<vector<int>> &g,int n)
        {
            int ans = 0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    for(int k=0; k<n; k++)
                    {
                        if(i != j && i != k && j !=k  && g[i][j] == 1 && g[j][k] ==1 && g[k][i] ==1)
                            ans++;
                    }
                }
            }
            return ans/3;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> g(n,vector<int> (n));
        for(auto &j:g)
            for(auto &i:j)
                cin>>i;
        Solution s;
        cout<<s.numberOfTriangles(g,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends