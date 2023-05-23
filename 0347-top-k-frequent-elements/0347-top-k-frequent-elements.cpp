class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto a : nums) mp[a]++;   //map will have value (no, freq)
        
        int n = nums.size();
        vector<int> freq[n+1];
        for(auto a : mp) freq[a.second].push_back(a.first);
        
        vector<int> ans;
        int cnt = 0;
        for(int i=n; i>=1; i--)
        {
            if(freq[i].size() == 0) continue;
            if(cnt == k) break;
            
            for(auto a : freq[i]) 
            {
                ans.push_back(a);
                cnt++;
                if(cnt == k) break;
            }
        }
        
        return ans;
    }
};