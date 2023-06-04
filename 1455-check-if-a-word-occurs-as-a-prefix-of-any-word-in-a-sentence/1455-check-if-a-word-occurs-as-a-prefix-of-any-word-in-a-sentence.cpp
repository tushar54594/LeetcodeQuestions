class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = searchWord.size();
        
        stringstream ss(sentence);
        string word;
        
        int i = 1;
        while(ss>>word)
        {
            if(word.substr(0, n) == searchWord) return i;
            i++;
        }
        
        return -1;
    }
};