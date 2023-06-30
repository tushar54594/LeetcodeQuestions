class Solution {
public:
    void print(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> ds){
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[ind]);
        print(ind + 1, nums, ans ,ds);
        
        ds.pop_back();
        while(ind < nums.size()-1 && nums[ind] == nums[ind+1]) ind++;
        
        print(ind + 1, nums, ans, ds);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end()); //sort so that duplicates are adjacent
        print(0, nums, ans, ds);
        return ans;
    }
};

/*
We cannot use set here because For eg it will treat [3,5] and [5,3] as different but they are same
*/