//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        map<char, int> m1;
        for(auto it : a) m1[it]++;
        
        map<char, int> m2;
        for(auto it : b) m2[it]++;
        
        if(m1.size() != m2.size()) return false;
        
        for(char ii='a'; ii<='z'; ii++)
        {
            if(m1.find(ii) != m1.end() && m2.find(ii) == m2.end()) return false;
            else if(m1.find(ii) == m1.end() && m2.find(ii) != m2.end()) return false;
            else if(m1.find(ii) != m1.end() && m2.find(ii) != m2.end())
            {
                if(m1[ii] != m2[ii]) return false;
            }
        }
        
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends