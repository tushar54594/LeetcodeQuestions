class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m; //map
        priority_queue<pair<int, char>> pq; //max heap
        
        for(char c: s)
            m[c]++;
        
        for(auto &it: m)
        {
            pq.push({it.second, it.first}); // will be in descending order of freq since max heap
        }
        
        string ans = "";
        while(!pq.empty())
        {
            pair<int, char> p = pq.top();
            pq.pop();
            while(p.first != 0)
            {
                ans += p.second;
                p.first--;
            }
        }
        
        return ans;
    }
};