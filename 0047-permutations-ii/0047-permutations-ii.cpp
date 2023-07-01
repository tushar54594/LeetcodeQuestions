class Solution {
public:
    void solve(int index, vector<int>& nums, set<vector<int>> &ans)
    {
        if(index == nums.size()){
            ans.insert(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(0, nums, ans);
        
        vector<vector<int>> v;
        for(auto a : ans) v.push_back(a);
        return v;
    }
};