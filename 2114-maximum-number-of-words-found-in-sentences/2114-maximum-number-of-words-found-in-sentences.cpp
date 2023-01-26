class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(int i=0; i<sentences.size(); i++)
        {
            int n = sentences[i].size();
            int count = 1;
            for(int j=0; j<n; j++)
            {
                if(sentences[i][j] == ' ')
                    count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};