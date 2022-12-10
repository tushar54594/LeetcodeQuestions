class Solution {
public:
    //It is same as AP
    //take a set and insert all the elements in it
    //check if element - diff and element + diff is present in the set
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int> s;
        for(int i=0; i<nums.size(); i++)
            s.insert(nums[i]);
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(nums[i]-diff) != s.end() && s.find(nums[i]+diff) != s.end())
                ans++;
        }
        return ans;
    }
};