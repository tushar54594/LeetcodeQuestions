class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        
        if(n == 1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> curr = intervals[0];
        for(int i=1; i<n; i++)
        {
            if(curr[1] < intervals[i][0])
            {
                ans.push_back(curr);
                curr = intervals[i];
            }
            else
                curr[1] = max(curr[1], intervals[i][1]);
        }
        
        ans.push_back(curr);
        return ans;
    }
};