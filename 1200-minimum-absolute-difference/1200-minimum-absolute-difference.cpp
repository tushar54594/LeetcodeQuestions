class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> a;
        sort(arr.begin(), arr.end());
        
        int mini = INT_MAX;
        for(int i=0; i<arr.size()-1; i++)
        {
            int diff = abs(arr[i+1] - arr[i]);
            mini = min(mini, diff);
        }
        
        for(int i=0; i<arr.size()-1; i++)
        {
            if(abs(arr[i+1] - arr[i]) == mini)
            {
                a.push_back(arr[i]);
                a.push_back(arr[i+1]);
            }
            
            if(a.size() == 2)
            {
                ans.push_back(a);
                a.pop_back();
                a.pop_back();
            }

        }
        return ans;
    }
};