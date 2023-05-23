class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int i = 0;
        for(int j=1; j<=n; j++)
        {
            int count = 1;
            while(j<n && chars[j] == chars[j-1])
            {
                count++;
                j++;
            }
            chars[i++] = chars[j-1];
            if(count > 1)
            {
                string cnt = to_string(count);
                for(auto a : cnt) chars[i++] = a;
            }
        }
        
        return i;
    }
};