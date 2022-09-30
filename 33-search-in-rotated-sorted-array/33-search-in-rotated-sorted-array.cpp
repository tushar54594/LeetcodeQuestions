class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            //check if target is equal to mid
            if(target == nums[mid])
                return mid;
            //check if left half is sorted
            else if(nums[s] <= nums[mid])
            {
                if(target >= nums[s] && target <= nums[mid]) //target lies in the left half
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            //if the left half is not sorted, then definitely the right half will be sorted
            else
            {
                if(target >= nums[mid] && target <= nums[e]) //target lies in the right half
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        
        return -1;
    }
};