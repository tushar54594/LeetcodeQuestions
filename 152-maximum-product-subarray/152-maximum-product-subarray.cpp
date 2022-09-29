class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod1 = INT_MIN;
        int currprod = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            currprod *= nums[i];
            maxprod1 = max(maxprod1, currprod);
            
            if(currprod == 0)
                currprod = 1;
        }
        
        int maxprod2 = INT_MIN;
        currprod = 1;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            currprod *= nums[i];
            maxprod2 = max(maxprod2, currprod);
            
            if(currprod == 0)
                currprod = 1;
        }
        
        return max(maxprod1, maxprod2);
    }
};