class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++) nums.push_back(i);
        
        //calculate (n-1)!
        int fact = 1;
        for(int i=n-1; i>=1; i--) fact *= i;
        
        string ans = "";
        k = k-1;  //we are taking 0 based indexing
        
        while(true){
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + k/fact);
            
            if(nums.size() == 0) break;
            k = k%fact;
            fact = fact/nums.size();
        }
        
        return ans;
    }
};