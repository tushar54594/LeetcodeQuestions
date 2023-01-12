class Solution {
public:
    int sumAfterDivision(vector<int>& nums, int divisor)
    {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += ceil((double)nums[i]/divisor);
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        int ans = high;
        while(low <= high)
        {
            int mid = (low+high)/2;
            //mid is a possible ans but we are looking for even smaller
            if(sumAfterDivision(nums, mid) <= threshold)
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};


//whenever we are increasing divisor, sum is getting reduced
//answer will always be between 1 and max(arr), because beyond max element, it will have a constant sum
//min sum that we can get is n(number of elements in the array)
//max um that we can get is summation of array elements(when we divide by max element)

