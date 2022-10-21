class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<double> prev(m+1, 0);
       
        //base case
        prev[0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=m; j>=1; j--) //we do from m to 1 because we are replacing the value which we are no more needing. We cannot go from left to right as we need the previous value
            {
                if(s[i-1] == t[j-1])
                    prev[j] = prev[j] + prev[j-1];
                else
                    prev[j] = prev[j];
            }
        }
        return (int)prev[m];
    }
};