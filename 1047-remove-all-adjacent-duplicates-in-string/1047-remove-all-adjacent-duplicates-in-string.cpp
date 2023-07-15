class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto a : s){
            if(st.size() == 0 || st.top() != a) st.push(a);
            else st.pop();
        }
        
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};