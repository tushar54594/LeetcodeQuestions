class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        
        while(s<e)
        {
            int mid = s + (e-s)/2;
            //if nums[mid] < nums[mid+1] , this means we are at the increasing part of the array
            //so the probable ans will lie to the right side of mid
            if(arr[mid] < arr[mid+1])
                s = mid + 1;
            else
                e = mid;
        }
        
        return s;
    }
    
};