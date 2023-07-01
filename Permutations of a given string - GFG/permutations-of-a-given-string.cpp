//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(int index, string &s, set<string> &ans)
	    {
	        if(index == s.size()){
	            ans.insert(s);
	            return;
	        }
	        
	        for(int i=index; i<s.size(); i++){
	            swap(s[index], s[i]);
	            solve(index+1, s, ans);
	            swap(s[index], s[i]);
	        }
	    }
	    
	    
		vector<string>find_permutation(string S)
		{
		    set<string> ans;
		    sort(S.begin(), S.end());
		    solve(0, S, ans);
		    vector<string> v;
		    for(auto a : ans) v.push_back(a);
		    
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends