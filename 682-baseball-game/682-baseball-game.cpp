class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i=0; i<ops.size(); i++)
        {
            if(ops[i] == "+")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.push(val1);
                s.push(val1 + val2);
            }
            else if(ops[i] == "C")
                s.pop();
            else if(ops[i] == "D")
            {
                int val = s.top();
                s.push(2*val);
            }
            else
                s.push(stoi(ops[i]));   //stoi(string)-> To convert string to integer  
        }
        
        int ans = 0;
        while(!s.empty())
        {
            int val = s.top();
            s.pop();
            ans += val;
        }
        return ans;
    }
};