class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        char ch, top;
        
        for(int i=0; i<s.length();i++){
            ch = s[i];
            
            //if opening bracket, push in stack
            if(ch == '(' || ch == '{' || ch == '[')
                stck.push(ch);
            else{
                //if closing bracket, check top of stack and pop
                if(!stck.empty()){
                    top = stck.top();
                    if((ch ==  ')' && top == '(') || ((ch ==  '}' && top == '{')) || ((ch ==  ']' && top == '[')))
                        stck.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
    }
        
        if(stck.empty())
            return true;
        else    
            return false;
    }
};