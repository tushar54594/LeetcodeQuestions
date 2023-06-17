class Solution {
public:
    int solve(map<pair<int,int>, int> &dp, int prev, int i, vector<int>& arr1, vector<int>& arr2)
    {
        if(i == arr1.size()) return 0;
        
        if(dp.find({i,prev}) != dp.end()) return dp[{i, prev}];
        
        int ans = 1e9+1;
        //find the next higher element of element in index i in arr2
        int id = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(arr1[i] > prev) //move on
            ans = min(ans, solve(dp, arr1[i], i+1, arr1, arr2));
        if(id < arr2.size())
            ans = min(ans, solve(dp, arr2[id], i+1, arr1, arr2)+1);
        
        return dp[{i, prev}] = ans;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int,int>, int> dp;  //dp -> {i, prev}
        int ans = solve(dp, -1, 0, arr1, arr2);
        if(ans >= 1e9+1) return -1;
        return ans;
    }
};