class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max_num = 10001; //for handling the infinity case(when both x1 and x2 are same, slope becomes infinity)
        //10001 by looking at the constraints
        int ans = 0;
        int n = points.size();
        for(int i=0; i<n-1; i++)
        {
            unordered_map<double, int> m;  //slope, count
            for(int j=i+1; j<n; j++)
            {
                if(points[i][0] == points[j][0])
                    m[max_num]++;
                else
                {
                    double slope = (double)(points[j][1] - points[i][1])/(double)(points[j][0] - points[i][0]);
                    m[slope]++;
                }
            }
            
            for(auto a : m)
                ans = max(ans, a.second+1);
        }
        
        return max(1, ans); //minimum 1 point will be there
    }
};