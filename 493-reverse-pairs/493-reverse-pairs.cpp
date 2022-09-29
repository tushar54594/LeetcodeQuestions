class Solution {
public:
    
    int merge(vector<int>& nums, int l, int m, int r)
    {
        int count = 0;
        int temp[nums.size()];
        int j = m+1;
        
        for(int i=l; i<=m; i++)
        {
            while(j<=r && (nums[i] > (long)2* nums[j]))
            {
                j++;
            }
            
            count += j - (m+1); //count elements to the left of j
        }
        
        
        int i = l;
        j = m+1;
        int k = 0;
        while(i<=m && j<=r)
        {
            if(nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        
        while(i<=m)
            temp[k++] = nums[i++];
        while(j<=r)
            temp[k++] = nums[j++];
        
        for(int i=l; i<=r; i++)
            nums[i] = temp[i-l];
        
        return count;
    }
    
    int mergeSort(vector<int>& nums, int l, int r)
    {
        int count = 0;
        if(l < r)
        {
            int m = (l+r)/2;
            count += mergeSort(nums, l, m);
            count += mergeSort(nums,m+1,r);
            count += merge(nums,l,m,r);
        }
        
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};