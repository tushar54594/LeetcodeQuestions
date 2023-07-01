class Solution {
public:
    void solve(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(index == arr.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        
        if(arr[index] <= target){
            ds.push_back(arr[index]);
            solve(index+1, target - arr[index], arr, ans, ds);
            ds.pop_back();
        }
        
        while(index < arr.size()-1 && arr[index] == arr[index+1]) index++;
        solve(index+1, target, arr, ans, ds);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        
        solve(0, target, candidates, ans, ds);
        return ans;
    }
};