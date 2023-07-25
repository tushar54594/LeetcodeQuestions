class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<int> v(n1+n2, -1);
        int k = 0;
        int i = 0;
        int j = 0;
        
        while(i<n1 && j<n2)
        {
            if(nums1[i] < nums2[j])
                v[k++] = nums1[i++];
            else
                v[k++] = nums2[j++];
        }
        
        while(i<n1)
            v[k++] = nums1[i++];
        
        while(j<n2)
            v[k++] = nums2[j++];
        
        int n = n1+n2;
        if(n%2 == 0) return (v[n/2-1] + v[n/2])/2.0;
        
        return v[n/2];
    }
};