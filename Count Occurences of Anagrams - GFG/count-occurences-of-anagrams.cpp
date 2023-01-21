//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int n = txt.size();
	    int k = pat.size();
	    int i = 0;
	    int j = 0;
	    unordered_map<char, int> mp;
	    for(int i=0; i<k; i++)
	        mp[pat[i]]++;
        
        int ans = 0;  //for storing the final answer
	    int count = mp.size();  //taki map bar bar traverse nahi karna pare
	    //count stores no of distinct variables
	    
	    while(j < n)
	    {
	        if(mp.find(txt[j]) != mp.end()) //this means element is present in map
	        {
	            mp[txt[j]]--;
    	        if(mp[txt[j]] == 0)
    	            count--;
	        }
	        
	        if(j-i+1 < k)
	            j++;
	        else if(j-i+1 == k)
	        {
	            if(count == 0)
	                ans++;
	            //jo kaam pehle kiye ho uska reverse karna hai bas window slide karne se pehle
	            if(mp.find(txt[i]) != mp.end())
	            {
	                mp[txt[i]]++;
    	            if(mp[txt[i]] == 1)
    	                count++;
	            }
	             i++;
	             j++;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends