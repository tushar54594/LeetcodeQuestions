class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(m+n,0);
        int index1 = 0, index2 = 0;
        int k = 0;
        
        while(index1<m && index2<n){
            if(nums1[index1] < nums2[index2]){
                nums[k++] = nums1[index1++];
            }
            else
                nums[k++] = nums2[index2++];
        }
        
        while(index1<m)
            nums[k++] = nums1[index1++];
        
        while(index2<n)
            nums[k++] = nums2[index2++];
        
        nums1 = nums;
    }
};