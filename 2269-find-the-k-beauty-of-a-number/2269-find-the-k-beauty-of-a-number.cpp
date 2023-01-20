class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j < n)
        {
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                string str = "";
                for(int k=i; k<=j; k++)
                    str += s[k];
                int div = stoi(str);
                if(div != 0 && num%div == 0)
                    ans++;
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};