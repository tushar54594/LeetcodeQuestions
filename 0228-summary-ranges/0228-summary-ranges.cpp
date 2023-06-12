class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        while(i < nums.size())
        {
            string s = to_string(nums[i]);
            int j = i;
            while(j<nums.size()-1 && nums[j+1] == nums[j]+1) j++;
            
            if(i != j)
            {
                s += "->";
                s += to_string(nums[j]);
            }
            ans.push_back(s);
            i = j+1;
        }
        
        return ans;
    }
};