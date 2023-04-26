class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        
        //array is already sorted
        if(nums[s] <= nums[e])
            return nums[s];
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            else if(nums[mid] < nums[mid-1])
                return nums[mid];
            else if(nums[s] <= nums[mid])
                s = mid + 1;
            else
                e = mid - 1;
        }
        
        return -1;
    }
};

/*
array will be in 2 parts
first element of the second part will be the ans
It will also be the only element whose prev element will be greater
for all the other elements, the prev element will be smaller

similarly
part1 last element is the only element whose next element is smaller than it

Also since it is a rotated sorted array, one part will always be sorted
And our ans will lie on the part which is not sorted
so find the part which is not sorted

Youtube: https://www.youtube.com/watch?v=Kcj2NGnuSNg
*/