class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto a : nums)
        {
            mp[a]++;   //map will have value (no, freq)
        }
        
        //create a min heap in which each value will be a pair of form (freq, no)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i = mp.begin(); i != mp.end(); i++)
        {
            pq.push({i->second, i->first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(pq.size() > 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};