//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(int index, string &s, string mapping[], int a[], int N, vector<string> &ans)
    {
        if(index == N){
            ans.push_back(s);
            return;
        }
        
        string val = mapping[a[index]];
        for(int i=0; i<val.size(); i++){
            s.push_back(val[i]);
            solve(index+1, s, mapping, a, N, ans);
            s.pop_back();
        }
    }
    
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        if(N == 0) return ans;
        
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s = "";
        
        solve(0, s, mapping, a, N, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends