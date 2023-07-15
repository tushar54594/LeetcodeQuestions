class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        int cnt = 0;
        for(auto a : s){
            if(a == '('){
                cnt++;
                st.push(a);
            }
            else if(a == ')'){
                ans = max(ans, cnt);
                cnt--;
                st.pop();
            } 
        }
        
        return ans;
    }
};