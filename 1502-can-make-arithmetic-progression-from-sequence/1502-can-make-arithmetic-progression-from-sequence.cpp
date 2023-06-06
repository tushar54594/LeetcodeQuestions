class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) {
        if(a.size() == 2) return true;
        
        sort(a.begin(), a.end());
        
        int diff = a[1] - a[0];
        for(int i=2; i<a.size(); i++)
        {
            if(a[i] - a[i-1] != diff) return false;
        }
        
        return true;
    }
};