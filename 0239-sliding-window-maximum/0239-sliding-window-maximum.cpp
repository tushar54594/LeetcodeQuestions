class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        
        deque<int> dq; //max heap
        while(j < n)
        {
            //deque me push karne se pehle usse chota jitna bhi element hai usko pop kardo
            //kyuki vo elements koi kaam ka nahi hai
            //ab deque ke front me hi max element hoga
            //agar jth index pe max hai toh j se pehle wla koi kaam ka nahi hai
            //j ke aage wla kaam me aa sakta hai agle iteration me
            
            while(!dq.empty() && dq.back() < nums[j])
                dq.pop_back();
            dq.push_back(nums[j]);
            
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                
                ans.push_back(dq.front());
                //ith index wla element agar present hoga deque me toh front me hi hoga
                //ith index vala element agar max tha toh vo front me hi hoga
                //toh agar front me hai toh pop kardo agle window me move karne se pehle
                if(nums[i] == dq.front())
                    dq.pop_front();
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};