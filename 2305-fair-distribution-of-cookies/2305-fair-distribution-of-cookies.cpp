class Solution {
public:
    
    void solve(int index, vector<int>& cookies, vector<int>& children, int k, int &ans)
    {
        if(index == cookies.size()){
            int unfairness = *max_element(children.begin(), children.end());
            ans = min(ans, unfairness);
            return;
        }
        
        //give each cookie to each child
        for(int i=0; i<k; i++){
            children[i] += cookies[index];
            solve(index+1, cookies, children, k, ans);
            children[i] -= cookies[index];
            if(children[i] == 0) break;
        }
    }
    
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        
        int ans = INT_MAX;
        solve(0, cookies, children, k, ans);
        
        return ans;
    }
};