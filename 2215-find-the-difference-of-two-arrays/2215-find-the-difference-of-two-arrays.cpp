class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer;
        set<int> s1, s2;
        
        for(auto val : nums1)
        {
            s1.insert(val);
        }
        
        for(auto val : nums2)
        {
            s2.insert(val);
        }
        
        vector<int> v1;
        for(auto val : s1)
        {
            if(s2.find(val) == s2.end())
                v1.push_back(val);
        }
        answer.push_back(v1);
        
        vector<int> v2;
        for(auto val : s2)
        {
            if(s1.find(val) == s1.end())
                v2.push_back(val);
        }
        answer.push_back(v2);
        
        return answer;
    }
};