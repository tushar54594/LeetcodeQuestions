class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = INT_MIN;
        int currprod = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            currprod *= nums[i];
            maxprod = max(maxprod, currprod);
            
            if(currprod == 0)
                currprod = 1;
        }
        
        currprod = 1;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            currprod *= nums[i];
            maxprod = max(maxprod, currprod);
            
            if(currprod == 0)
                currprod = 1;
        }
        
        return maxprod;
    }
};