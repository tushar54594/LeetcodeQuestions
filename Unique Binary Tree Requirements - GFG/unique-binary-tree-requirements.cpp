//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        if(a == 2 && b == 1 || a == 1 && b == 2) return true;
        if(a == 2 && b == 3 || a == 3 && b == 2) return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    }
}
// } Driver Code Ends