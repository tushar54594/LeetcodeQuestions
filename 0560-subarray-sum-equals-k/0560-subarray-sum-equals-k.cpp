class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(sum == k)
                count++;
            //y-k = x since we have x+y=k
            if(mp.find(sum-k) != mp.end())
                count += mp[sum-k];
            
            //if we found the sum in the map, we increment it's count
            if(mp.find(sum) != mp.end())
                mp[sum]++;
            else
                mp[sum] = 1;
        }
        
        return count;
    }
};