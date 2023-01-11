class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for(auto a : nums)
        {
            if(a != 0)
                s.insert(a);
        }
        
        return s.size();
    }
};