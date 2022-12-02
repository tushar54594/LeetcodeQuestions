class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0; //to store count of 0
        int i = 0;
        int j = 0;
        
        int maxi = INT_MIN;
        while(j < nums.size())
        {
            if(nums[j] == 0)
                count++;
            if(count <= k)
            {
                maxi = max(maxi, j-i+1);
                j++;
            }
            else if(count > k)
            {
                while(count > k)
                {
                    if(nums[i] == 0)
                        count--;
                    i++;
                }
                
                if(count == k)
                    maxi = max(maxi, j-i+1);
                
                j++;
            }
        }
        return maxi;
    }
};