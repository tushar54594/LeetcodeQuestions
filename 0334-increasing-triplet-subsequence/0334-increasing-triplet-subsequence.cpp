class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        for(auto a : nums)
        {
            if(a < first) first = a;
            else if(a > first && a < second) second = a;
            else if(a > second) return true;
        }
        
        return false;
    }
};