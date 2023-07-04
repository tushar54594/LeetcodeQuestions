class Solution {
public:
    void solve(int ind, vector<int>& candidates, int target, vector<int>&v, vector<vector<int>>&ans, int sum){

    if(sum > target) return;
    
    if(ind==candidates.size()){
        if(sum==target){
            ans.push_back(v);
        }
        return;
    }

       
       v.push_back(candidates[ind]);
       solve(ind+1,candidates,target,v,ans,sum+candidates[ind]);
        v.pop_back();

      while(ind<candidates.size()-1 && candidates[ind]==candidates[ind+1])ind++;


      
    solve(ind+1,candidates,target,v,ans,sum);


   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());

        vector<vector<int>>ans;

         vector<int>v;


         solve(0,candidates,target,v,ans,0);

         
       
        return ans;
    }
};