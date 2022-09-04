class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        //fix a
        for(int i=0; i<n-3; i++)
        {
            //ignore the duplicates
            if(i == 0 || (i>0 && nums[i] != nums[i-1]))
            {
                //fix b
                for(int j=i+1; j<n-2; j++)
                {
                    //ignore the duplicates
                    if(j == i+1 || (j>i+1 && nums[j] != nums[j-1]))
                    {
                        int low = j+1, high = n-1;
                        long sum = long(target) - nums[i] - nums[j];

                        while(low<high)
                        {
                            if(nums[low] + nums[high] == sum)
                            {
                                vector<int> arr;
                                arr.push_back(nums[i]);
                                arr.push_back(nums[j]);
                                arr.push_back(nums[low]);
                                arr.push_back(nums[high]);
                                ans.push_back(arr);

                                while(low<high && nums[low] == nums[low+1])
                                    low++;
                                while(low<high && nums[high] == nums[high-1])
                                    high--;

                                low++;
                                high--;

                            }
                            else if(nums[low] + nums[high] < sum)
                                low++;
                            else 
                                high--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};