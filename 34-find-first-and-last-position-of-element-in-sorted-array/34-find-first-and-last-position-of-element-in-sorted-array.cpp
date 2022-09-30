class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        //first occurence
        int s = 0;
        int e = nums.size()-1;
        int firstOccur = -1; //if we do not found the target, answer should be -1
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(target == nums[mid])
            {
                firstOccur = mid;
                e = mid - 1;
            }
            else if(target < nums[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        
        //last occurence
        s = 0;
        e = nums.size()-1;
        int lastOccur = -1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(target == nums[mid])
            {
                lastOccur = mid;
                s = mid + 1;
            }
            else if(target < nums[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        
        ans.push_back(firstOccur);
        ans.push_back(lastOccur);
        return ans;
    }
};