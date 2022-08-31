class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        
        int k = 0;
	    for(int i=0; i<pos.size(); i++)
	    {
	        nums[k] = pos[i];
	        k = k+2;
	    }
	    
	    k = 1;
	    for(int i=0; i<neg.size(); i++)
	    {
	        nums[k] = neg[i];
	        k = k+2;
	    }
        
        return nums;
    }
};