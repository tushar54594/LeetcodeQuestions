class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0)
            return 0;
        
        //to eliminate whitespaces
        int i=0;
        while(i<s.size() && s[i] == ' ')
            i++;
        s = s.substr(i); //from ith index ---> end of the string
        
        //checking for sign
        int sign = 1;
        long ans = 0;
        if(s[0] == '-')
            sign = -1;
        
        int max = INT_MAX, min = INT_MIN;
        //if -ve sign was present then we have to start from 1st index otherwise from oth index only
        i = (s[0] == '-' || s[0] == '+') ? 1 : 0; 
        
        while(i < s.size())
        {
            if(s[i] == ' ' || !isdigit(s[i]))//if there is empty space or some character occurs then break
                break;
            
            ans = ans*10 + s[i] - '0';
            if(sign == 1 && ans>max)
                return max;
            if(sign == -1 && -ans < min)
                return min;
            
            i++;
        }
        return ans*sign;
    }
};