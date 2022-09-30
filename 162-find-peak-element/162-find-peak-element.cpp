class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return 0;
        
        //check for 1st element
        if(nums[0] > nums[1])
            return 0;
        
        //check for last element
        if(nums[n-1] > nums[n-2])
            return n-1;
            
        //we have already checked for the first and last elements, so check for the remaining elements
        //i.e. form the 1st index to the 2nd last index
        for(int i=1; i<n-1; i++)
        {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        }
        
        return -1;
    }
};