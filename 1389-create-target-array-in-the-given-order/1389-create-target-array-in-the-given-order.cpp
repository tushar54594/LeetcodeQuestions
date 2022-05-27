class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for(int i=0; i<index.size(); i++)
        {
            target.insert(target.begin() + index[i], nums[i]);
            //first parameter is used to define the position and second one is used for the element to insert
        }
        return target;
    }
};