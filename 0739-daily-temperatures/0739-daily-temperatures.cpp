class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        
        stack<int> s;
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && temperatures[s.top()] <= temperatures[i])
                s.pop();
            
            if(s.empty())
            {
                ans[i] = 0;
                s.push(i);
            }
            else
            {
                ans[i] = s.top()-i;
                s.push(i);
            }
        }
        
        return ans;
    }
};

/*
start from back
use stack - create a monotonic stack
start iterating from back
- it is same as next greater element but instead of storing the element, we are storing the indexs in stack since we need the difference b/w the elements
*/