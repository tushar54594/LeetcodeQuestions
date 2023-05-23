//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int n = s.size();
        stack<string> st;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '.') continue;
            else
            {
                string word = "";
                while(i<s.size() && s[i] != '.') 
                {
                    word += s[i];
                    i++;
                }
                st.push(word);
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            string str = st.top();
            st.pop();
            ans += str;
            if(!st.empty()) ans += '.';
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends