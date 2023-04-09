class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto a : asteroids)
        {
            if(st.empty() || a > 0) 
                st.push(a);
            else //a is -ve and stack is not empty
            {
                while(true)
                {
                    int top = st.top();
                    if(top < 0)
                    {
                        st.push(a);
                        break;
                    }
                    else if(top == -a)
                    {
                        st.pop();
                        break;
                    }
                    else if(top < -a)
                    {
                        st.pop();
                        if(st.empty())
                        {
                            st.push(a);
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        
        vector<int> ans(st.size());
        for(int i = st.size()-1; i>=0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};

/*
collision will only happen when in the order + -
*/