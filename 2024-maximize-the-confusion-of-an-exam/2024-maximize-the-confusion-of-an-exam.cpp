class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i = 0;
        int j = 0;
        
        int ans = 0;
        int cnt = 0;
        //max substring of 'T' which contains at most k 'F'
        while(j<s.size()){
            if(s[j] == 'F') cnt++;
            if(cnt <= k)
            {
                ans = max(ans, j-i+1);
                j++;
            }
            else if(cnt > k){
                while(cnt > k){
                    if(s[i] == 'F') cnt--;
                    i++;
                }
                
                if(cnt <= k) ans = max(ans, j-i+1);
                
                j++;
            }
        }
        
        //max substring of 'F' which contains at most k 'T'
        cnt = 0;
        i = 0;
        j = 0;
        while(j<s.size()){
            if(s[j] == 'T') cnt++;
            if(cnt <= k)
            {
                ans = max(ans, j-i+1);
                j++;
            }
            else if(cnt > k){
                while(cnt > k){
                    if(s[i] == 'T') cnt--;
                    i++;
                }
                
                if(cnt <= k) ans = max(ans, j-i+1);
                
                j++;
            }
        }
        
        return ans;
    }
};