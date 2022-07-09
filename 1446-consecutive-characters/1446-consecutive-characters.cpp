class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int maxi = 0;
        for(int i=0; i<n; i++)
        {
            int count = 1;
            for(int j=i; j<n; j++)
            {
                if(s[j] == s[j+1])
                    count++;
                else
                    break;
            }
            maxi = max(maxi, count);
        }
        
        return maxi;
    }
};