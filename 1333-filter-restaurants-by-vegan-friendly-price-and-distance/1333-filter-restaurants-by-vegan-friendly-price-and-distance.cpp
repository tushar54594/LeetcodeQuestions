class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>> v;
        for(auto a : restaurants)
        {
            if(((veganFriendly == 1 && a[2] == 1) || (veganFriendly == 0))&& a[3]<=maxPrice && a[4]<=maxDistance)
            {
                v.push_back({a[1], a[0]});
            }
        }
        //By default the sort function sorts the vector elements on basis of first element of pairs.
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        vector<int> ans;
        for(auto a : v)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};