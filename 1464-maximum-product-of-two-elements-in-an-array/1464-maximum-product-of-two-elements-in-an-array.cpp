class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int largest = 0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int maxi = (nums[i]-1)*(nums[j]-1);
                largest = max(largest,maxi);
            }
        }
        return largest;
    }
};