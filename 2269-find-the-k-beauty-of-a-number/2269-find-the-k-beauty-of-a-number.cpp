class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);  //convert the number to string
        int i = 0;
        int j = 0;
        
        int ans = 0;
        while(j < s.size())
        {
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                // on hiting the window size
                // extract window string and convert to int
                // check if it follows the given condition
                string str = s.substr(i, k); //first parameter-start index, second parameter-length
                int n = stoi(str);
                if(n != 0 && num%n == 0)
                    ans++;
                
                i++;
                j++;
            }
        }
        return ans;
    }
};