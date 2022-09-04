class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        int life1 = 0;
        int life2 = 0;
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == candidate1)
                life1++;
            else if(nums[i] == candidate2)
                life2++;
            else if(life1 == 0)
            {
                candidate1 = nums[i];
                life1 = 1;
            }
            else if(life2 == 0)
            {
                candidate2 = nums[i];
                life2 = 1;
            }
            else
            {
                life1--;
                life2--;
            }
        }
        
        //In this question, the issue is we can have 0 or 1 answers also, so we are not sure if the               //candidate obtained is our ans or not. So we have to iterate over the array again and check 
        //the count of both the candidates and if they are greater than n/3, then it is our ans
        
        int count1 = 0;
        int count2 = 0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == candidate1)
                count1++;
            else if(nums[i] == candidate2)
                count2++;
        }
        
        if(count1 > n/3)
            ans.push_back(candidate1);
        if(count2 > n/3)
            ans.push_back(candidate2); 
        
        return ans;
    }
};