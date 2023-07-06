class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int mini = INT_MAX;
        int sum = 0;
        
        while(j < nums.size()){
            sum += nums[j];
            
            if(sum < target) j++;
            else if(sum == target){
                mini = min(mini, j-i+1);
                j++;
            }
            else if(sum > target){
                while(sum > target){
                    sum -= nums[i];
                    mini = min(mini, j-i+1);
                    i++;
                }
                
                if(sum == target) mini = min(mini, j-i+1);
                
                j++;
            }
        }
        
        return mini == INT_MAX ? 0 : mini;
    }
};