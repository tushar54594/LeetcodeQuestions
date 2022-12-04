class Solution {
public:
    //idea: Maintain a sliding window where there is at most one zero on it.
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int count = 0;  //no of zeroes
        int maxi = 0;
        
        while(j < nums.size())
        {
            if(nums[j] == 0)
                count++;
            
            if(count <= 1)
            {
                maxi = max(maxi, j-i);  //we do not do j-i+1 since we have to delete 1 element
                j++;
            }
            else if(count > 1)
            {
                while(count > 1)
                {
                    if(nums[i] == 0)
                        count--;
                    i++;
                }
                
                if(count == 1)
                    maxi = max(maxi, j-i);
                
                j++;
            }
        }
        return maxi;
    }
};