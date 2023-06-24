class Solution {
public:
    int height(int i,int j,vector<int>& rods,unordered_map<int,unordered_map<int,int>>& mp){
        int n=rods.size();
        
        if(i==n){
            if(j==0) return 0;
            return INT_MIN;
        }
        
        if(mp[i].find(j)!=mp[i].end()) return mp[i][j];
        
        int ans=INT_MIN;
        ans=height(i+1,j,rods,mp);
        
        ans = max(ans,rods[i]+height(i+1,j+rods[i],rods,mp));
        ans = max(ans,height(i+1,j-rods[i],rods,mp));
        return mp[i][j] = ans;
    }
    
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,unordered_map<int,int>>mp;
        return height(0,0,rods,mp);
    }
};