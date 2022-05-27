class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int larg = 0;
        for(int i=0; i<accounts.size(); i++)
        {
            int curr = 0;
            for(int j=0; j<accounts[0].size(); j++)
            {
                curr += accounts[i][j];
            }
            larg = max(larg, curr);
        }
        return larg;
    }
};