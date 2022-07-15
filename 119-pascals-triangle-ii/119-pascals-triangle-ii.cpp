class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        for(int i=0; i<=rowIndex; i++)
        {
            vector<int> arr(i+1, 1);
            for(int j=1; j<i; j++)   //since the first and last element is always 1
            {
                arr[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(arr);
        }
        return ans[rowIndex];
    }
};