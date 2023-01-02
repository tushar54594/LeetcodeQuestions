class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        //first letter is capital
        if(isupper(word[0]))
        {
            //check the second letter
            
            //second letter is also capital
            if(isupper(word[1]))
            {
                //then all the remaining letters should be capital
                for(int i=2; i<n; i++)
                {
                    if(islower(word[i]))
                        return false;
                }
            }
            //second letter is small
            else
            {
                //then all the remaining letters should be small
                for(int i=2; i<n; i++)
                {
                    if(isupper(word[i]))
                        return false;
                }
            }
        }
        //first letter is small
        else
        {
            //then all the remaining letters should be small
            for(int i=1; i<n; i++)
            {
                if(isupper(word[i]))
                    return false;
            }
        }
        
        return true;
    }
};