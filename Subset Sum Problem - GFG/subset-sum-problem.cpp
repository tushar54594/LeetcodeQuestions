//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false)); 
        //now we don't need -1 so take a boolean vector 
        
        //first write the base cases
        for(int i=0; i<n; i++)
            dp[i][0] = true;
        if(arr[0] <= sum)
            dp[0][arr[0]] = true;
        
        for(int index=1; index<n; index++)
        {
            for(int target=1; target<=sum; target++)
            {
                bool notTake = dp[index-1][target];
                bool take = false;
                if(arr[index] <= target) 
                    take = dp[index-1][target-arr[index]];
            
                dp[index][target] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends