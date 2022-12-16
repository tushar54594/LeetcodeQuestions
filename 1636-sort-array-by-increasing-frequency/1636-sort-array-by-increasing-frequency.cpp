class Solution {
public:
    /*-1 is multiplied here because we have to get least frequency element first, so declared maxHeap will behave as minHeap and we get least frequency element first.

Now, the question is, i should have just used minHeap ?

The answer to this question is : if the frequency is same, then i need elements in decreasing order, that's where maxHeap come into play, so a maxHeap is declared.
Long answer short : -1 is multiplied to convert maxHeap to minHeap.*/
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto a : nums)
            m[a]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto a : m)
            pq.push({-a.second, a.first});
        
        vector<int> ans;
        while(pq.size() > 0)
        {
            int x = -pq.top().first;
            for(int i=0; i<x; i++)
                ans.push_back(pq.top().second);
            
            pq.pop();
        }
        return ans;
    }
};