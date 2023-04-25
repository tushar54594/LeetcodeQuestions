//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    
        sort(a.begin(), a.end());
        int i=0,j=0;
        long long diff = INT_MAX;
        while(j<n)
        {
           if(j-i+1 < m)
            j++;
           else if(j-i+1 == m)
           {
               diff = min(diff, a[j] - a[i]);
               i++;
               j++;
           }
        }
        return diff;
    }   
};

/*
The idea is based on the observation that to minimize the difference, we must choose consecutive elements 
from a sorted packet. We first sort the array arr[0..n-1], then find the subarray of size m with the 
minimum difference between the last and first elements.
*/

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends