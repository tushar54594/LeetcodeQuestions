class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        
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