class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(auto x : arr)
            mp[x]++;
        
        int maxi = 0;
        for(auto x : mp)
        {
            if(x.second == x.first)
            {
                int val = x.first;
                maxi = max(maxi, val);
            }
        }
        if(maxi == 0)
            return -1;
        
        return maxi;
    }
};