class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(auto a : arr) sum += a;
        
        if(sum%3 != 0) return false;
        
        int s = sum/3;
        
        int cnt = 0;
        int curr_sum = 0;
        for(int i=0; i<arr.size(); i++)
        {
            curr_sum += arr[i];
            if(curr_sum == s)
            {
                cnt++;
                curr_sum = 0;
            }
        }
        
        if(cnt >= 3) return true;
        
        return false;
    }
};