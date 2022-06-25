class Solution {
public:
    int digits(int n)
    {
        int cnt = 0;
        while(n>0)
        {
            cnt++;
            n = n/10;
        }
        return cnt;
    }
    
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(digits(nums[i]) % 2 == 0)
                count++;
        }
        return count;
    }
};