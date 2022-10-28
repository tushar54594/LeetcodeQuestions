class Solution {
public:
    bool check(string &s1, string &s2)
    {
        if(s1.size() != s2.size()+1)  //s1 is longer string and s2 is shorter one
            return false;
        
        //use two pointer approach to check if s1 can be created by adding 1 character to s2
        int first = 0;
        int second = 0;
        while(first < s1.size())  //s1 is bigger
        {
            if(second<s2.size() && s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
                first++;
        }
        
        if(first == s1.size() && second == s2.size())
            return true;
        
        return false;
    }
    
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        //sort according to length
        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });  
        
        int n = words.size();
        vector<int> dp(n, 1); //initialize the dp array to 1
        int maxi = 1;
        
        for(int index=0; index<n; index++)
        {
            for(int prev=0; prev<index; prev++)
            {
                if(check(words[index], words[prev]))
                    dp[index] = max(1 + dp[prev], dp[index]);
            }
            maxi = max(maxi, dp[index]);
        }
        return maxi; 
    }
};