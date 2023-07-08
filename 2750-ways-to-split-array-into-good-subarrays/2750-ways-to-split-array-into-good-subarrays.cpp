class Solution {
public:
    int mod = 1e9+7;
    
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 0;
        int cntZeros = 0;
        int cntOnes = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) cntZeros++;
            else{
                cntOnes++;
                if(cntOnes == 1) ans = 1;
                else ans = (ans * (cntZeros+1)%mod)%mod;
                
                cntZeros = 0;
            }
        }
        
        return (int)ans;
    }
};

/*
Count no of zeros b/w 2 1's
n zeros => n+1 splits 
multiply it
*/