class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[1] < b[1]) return true; //sort aaccording to end
        else if(a[1] == b[1]) return a[0] < b[0]; //if end same, then sort according to start
        return false;
    }
    
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), cmp);
        int ans = 0;
        set<int> days;
        for(int i=1; i<=1e5; i++) days.insert(i);
        
        for(auto a : events){
            int start = a[0];
            int end = a[1];
            
            auto it = days.lower_bound(start);
            if(it == days.end() || *it > end){
                continue;
            }
            else{
                ans++;
                days.erase(it);
            }
        }
        
        return ans;
    }
};