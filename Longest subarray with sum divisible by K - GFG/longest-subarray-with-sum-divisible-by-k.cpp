//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int, int> m;
	    m.insert({0, -1});  //{rem, index}
	    //if we get rem 0 anywhere going forward, so the whole subarray is divisible by k
	    //so to calculate the length of that subarray we do this
	    
	    int ans = 0;
	    int sum = 0;
	    for(int i=0; i<n; i++)
	    {
	        sum += arr[i];
	        int rem = sum%k;
	        if(rem < 0) rem += k; //for -ve no
	        
	        if(m.find(rem) == m.end())
	            m.insert({rem, i});
	        else
	            ans = max(ans, i - m[rem]);
	    }
	    return ans;
	}
	
	/*
	1.calculate prefix sum
	2.find the remainder when the sums are divided by k'
	3.if two sums have the same remainder, then we will get a subarray
	Eg:
	Given: 5 2 1 4   7 8 2 5
	Sum:   5 7 8 12 19 27 29
	Rem: 0 2 1 2 0  1  0  2 
	(when divided by 3)
	when we see a 0 as the rem => the entire subarray is multiple of k
	
	NOTE:
	if rem is -ve, then just add k to it to get the corresponding +ve rem
	*/
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends