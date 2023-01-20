class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        double sum = 0;
        double avg = INT_MIN;
        while(j < n)
        {
            sum += nums[j];
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                avg = max(avg, sum/k);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        
        return avg;
    }
};