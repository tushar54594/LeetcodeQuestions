class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        
        if(s == goal)
            return true;
        
        s = s + s; 
        int pos = s.find(goal);
        if(pos > s.size()-1)
            return false;
        
        return true;
    }
};