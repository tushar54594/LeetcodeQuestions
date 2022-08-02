class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0; i<nums.size(); i=i+2)
        {
            arr1.push_back(nums[i]);
        }
        for(int i=1; i<nums.size(); i=i+2)
        {
            arr2.push_back(nums[i]);
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end(), greater<int>());
        
        vector<int> ans(nums.size());
        int index = 0;
        for(int i=0; i<nums.size(); i=i+2)
        {
            ans[i] = arr1[index++];
        }
        
        index = 0;
        for(int i=1; i<nums.size(); i=i+2)
        {
            ans[i] = arr2[index++];
        }
        return ans;
    }
};