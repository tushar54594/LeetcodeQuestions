class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        
        for(int i=1; i<n; i++)
        {
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            int notpick = 0 + prev;
            int curr = max(pick, notpick);
            
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> temp1(n-1);
        for(int i=0; i<n-1; i++)
            temp1.push_back(nums[i]);
        int ans1 = solve(temp1);
        
        vector<int> temp2(n-1);
        for(int i=1; i<n; i++)
            temp2.push_back(nums[i]);
        int ans2 = solve(temp2);
        
        return max(ans1, ans2);
    }
};