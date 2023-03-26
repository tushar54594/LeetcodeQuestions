//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	if(N == 1)
    	    return 2*A[0];
    	
    	int max = A[0];
    	int min = A[0];
    	if(A[1] > A[0])
    	{
    	    max = A[1];
    	    min = A[0];
    	}
    	else{
    	    max = A[0];
    	    min = A[1];
    	}
    	
    	for(int i=2; i<N; i++)
    	{
    	    if(A[i] > max)
    	        max = A[i];
    	    if(A[i] < min)
    	        min = A[i];
    	}
    	    
    	return max + min;
    	
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
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends