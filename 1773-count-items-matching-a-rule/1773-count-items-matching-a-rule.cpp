class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for(int i=0; i<items.size(); i++)
        {
            if(ruleKey == "type")
            {
                if(items[i][0] == ruleValue)
                    ans++;
            }
            else if(ruleKey == "color")
            {
                if(items[i][1] == ruleValue)
                    ans++;
            }
            else if(ruleKey == "name")
            {
                if(items[i][2] == ruleValue)
                    ans++;
            }
        }
        return ans;
    }
};