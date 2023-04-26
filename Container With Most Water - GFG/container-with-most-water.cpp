//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    if(len == 1) return 0;
    long long ans = 0;
    int s = 0;
    int e = len-1;
    while(s <= e)
    {
        long long area = min(A[s] , A[e]) * (e-s);
        ans = max(ans, area);
        
        if(A[s] < A[e])
            s++;
        else
            e--;
    }
    return ans;
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends