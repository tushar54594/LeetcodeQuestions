class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        for(int i=0; i<number.size(); i++)
        {
            if(number[i] == digit)
            {
                string temp;
                temp = number.substr(0, i) + number.substr(i+1);
                ans = max(ans, temp);
            }
        }
        
        return ans;
    }
};