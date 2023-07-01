class Solution {
public:
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    
    void solve(int index, int sum, int k, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(index == 9){
            if(sum == target && ds.size() == k) ans.push_back(ds);
            return;
        }
        
        
        ds.push_back(arr[index]);
        sum += arr[index];
        solve(index+1, sum, k, target, ans, ds);
        
        ds.pop_back();
        sum -= arr[index];
        solve(index+1, sum, k, target, ans, ds);
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(0, 0, k, n, ans, ds);
        return ans;
    }
};