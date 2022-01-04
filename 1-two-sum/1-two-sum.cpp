class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i =0; i<nums.size(); i++){
            int n1 = nums[i];
            for(int j = i + 1; j<nums.size(); j++){
                int n2 = nums[j];
                if(target == (n1 + n2)){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};