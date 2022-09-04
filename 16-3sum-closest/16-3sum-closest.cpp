class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[n-1];
        
        //we are going till n-2 since we need 3 elements
        for(int i=0; i<n-2; i++)
        {
            int start = i+1;
            int end = n-1;
            
            while(start < end)
            {
                int currSum = nums[i] + nums[start] + nums[end];
                if(currSum == target)
                    return currSum;
                else if(currSum < target)
                    start++;
                else
                    end--;
                
                if(abs(currSum-target) < abs(closestSum-target))
                    closestSum = currSum;
            }
        }
        return closestSum;
    }
};