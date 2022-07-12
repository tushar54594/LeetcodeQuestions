class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> a;
        sort(arr.begin(), arr.end());
        
        int mini = INT_MAX;
        for(int i=0; i<arr.size()-1; i++)
        {
            int diff = arr[i+1] - arr[i];
            mini = min(mini, diff);
        }
        
        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr[i+1] - arr[i] == mini)
            {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};