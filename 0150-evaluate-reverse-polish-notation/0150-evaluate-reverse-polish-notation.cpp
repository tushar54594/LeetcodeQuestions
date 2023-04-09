class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n1, n2;
        for(auto a : tokens)
        {
            if(a == "+")
            {
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                st.push(n2+n1);
            }
            else if(a == "-")
            {
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                st.push(n2-n1);
            }
            else if(a == "*")
            {
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                st.push(n2*n1);
            }
            else if(a == "/")
            {
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                st.push(n2/n1);
            }
            else
                st.push(stoi(a));
        }

        return st.top();
    }
};