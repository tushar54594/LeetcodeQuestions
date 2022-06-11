class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        
        int carry = 0;
        while(i >= 0 || j >= 0 || carry != 0)
        {
            int ival = i >= 0 ? num1[i] - '0' : 0;
            i--;
            
            int jval = j >= 0 ? num2[j] - '0' : 0;
            j--;
            
            int sum = ival + jval + carry;
            res.push_back(sum%10 + '0');
            carry = sum/10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};