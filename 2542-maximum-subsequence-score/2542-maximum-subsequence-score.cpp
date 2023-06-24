class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        vector<pair<int,int>> nums;
        for(int i=0; i<n; i++){
            nums.push_back({nums2[i], nums1[i]});
        }
        
        sort(nums.rbegin(), nums.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long currSum = 0;
        for(int i=0; i<k-1; i++){
            pq.push(nums[i].second);
            currSum += nums[i].second;
        }
        
        long long ans = 0;
        
        for(int i=k-1; i<n; i++){
            currSum += nums[i].second;
            ans = max(ans, (long long)currSum * nums[i].first);
            
            if(pq.size() > 0 && pq.top() < nums[i].second){
                currSum -= pq.top();
                pq.pop();
                pq.push(nums[i].second);
            }
            else
                currSum -= nums[i].second;
        }
        
        return ans;
    }
};