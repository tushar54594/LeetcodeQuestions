class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int temp = 1;
        vector<int> ans;
        
        //calculate the left product of each index
        for(int i=0; i<n; i++)
        {
            ans.push_back(temp);
            temp = temp*nums[i];
        }
        
        //iterate from right to left
        temp = 1;
        for(int i=n-1; i>=0; i--)
        {
            ans[i] = temp*ans[i];
            temp = temp*nums[i];
        }
        return ans;
    }
};