class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans, res;
        res = nums;
        
        sort(res.begin(), res.end());
        
        int num1, num2; 
                    
        int i = 0, j = res.size()-1;
        while(i<res.size() && j>=0)
        {
            if(res[i] + res[j] == target)
            {
                num1 = res[i];
                num2 = res[j];
                break;
            }
            else if(res[i] + res[j] < target)
                i++;
            else 
                j--;
        }
        
        //since we sorted the array and now we want the original index of the number which we got as the answer
        for(int i=0; i<nums.size(); i++)
        {
            if(num1 == nums[i]) 
                ans.push_back(i);
            else if(num2 == nums[i])
                ans.push_back(i);
        }
        
        return ans;
    }
};