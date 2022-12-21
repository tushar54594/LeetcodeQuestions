class Solution {
public:
    bool isPalindrome(string str)
    {
        int s = 0;
        int e = str.size()-1;
        while(s < e)
        {
            if(str[s] == str[e])
            {
                s++;
                e--;
            }
            else
                return false;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++)
        {
            if(isPalindrome(words[i]))
                return words[i];
        }
        return "";
    }
};