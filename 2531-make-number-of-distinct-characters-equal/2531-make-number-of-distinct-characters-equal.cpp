class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char, int> m1, m2;
        for(auto a : word1)
            m1[a]++;
        for(auto a : word2)
            m2[a]++;
        
        for(char ch1='a'; ch1<='z'; ch1++)
        {
            for(char ch2='a'; ch2<='z'; ch2++)
            {
                if(m1[ch1]>0 && m2[ch2]>0) //character should be present in the words in order to swap
                {
                    //swap ch1 and ch2
                    m1[ch1]--;
                    m1[ch2]++;
                    m2[ch1]++;
                    m2[ch2]--;
                    //check no of unique characters
                    int count1 = 0, count2 = 0;
                    for(char ch='a'; ch<='z'; ch++)
                    {
                        if(m1[ch] > 0)
                            count1++;
                        if(m2[ch] > 0)
                            count2++;
                    }
                    if(count1 == count2)
                        return true;
                    
                    //undo the swap so that we can perform a new swap and check 
                    m1[ch1]++;
                    m1[ch2]--;
                    m2[ch1]--;
                    m2[ch2]++;
                }
            }
        }
        return false;
    }
};