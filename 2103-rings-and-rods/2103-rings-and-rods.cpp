class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, set<char>> m;
        
        for(int i=0; i<rings.size(); i+=2){
            m[rings[i+1] - '0'].insert(rings[i]);
        }
        
        int ans = 0;
        for(auto a : m){
            if(a.second.size() == 3) ans++;
        }
        
        return ans;
    }
};