class Solution {
public:
    //find minimum sum subarray of length n-k, thus totalSum - minSum will be the ans
    //since we have to pick elements from front or back only
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int totalSum = 0;
        for(int i=0; i<n; i++)
            totalSum += cardPoints[i];
        
        if(n == k)
            return totalSum;
        
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(j < n)
        {
            sum += cardPoints[j];
            if(j-i+1 < n-k)
                j++;
            else if(j-i+1 == n-k)
            {
                ans = min(ans, sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        return totalSum - ans;
    }
};