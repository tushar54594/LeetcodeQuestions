//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long count(long long a, long long b)
    {
        int c = 0;
        while(b <= a)
        {
            b = b<<1;
            c++;
        }
        return c-1;
    }
    
    long long divide(long long a, long long b) 
    {
        if(a == 0) return 0;
        if(b == 1) return a;
        
        bool sign = (a<0)^(b<0);
        a = abs(a);
        b = abs(b);
        
        long long ans = 0;
        while(b <= a)
        {
            long long c = count(a, b);
            a -= b<<c;
            ans += 1<<c;
        }
        return (sign) ? -ans : ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends