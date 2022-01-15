class Solution {
    
public:
    void print(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> ds){
        if(ind == arr.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[ind]);
        print(ind + 1, arr, ans ,ds);
        ds.pop_back();
        print(ind + 1, arr, ans, ds);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        print(0, nums, ans, ds);
        return ans;
    }
};