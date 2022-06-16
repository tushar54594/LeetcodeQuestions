class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> height;
        height = heights;
        
        sort(heights.begin(), heights.end());
        vector<int> expected;
        for(int i=0; i<heights.size(); i++)
            expected.push_back(heights[i]);
        
        int count = 0;
        for(int i=0; i<height.size(); i++)
        {
            if(height[i] != expected[i])
                count++;
        }
        return count;
    }
};