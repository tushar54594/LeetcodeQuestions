class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> s;
        int size = target.size();
        int index = 0;
        
        for(int i=1; i<=n; i++)
        {
            if(i <= target[size-1])
            {
                if(target[index] == i)
                {
                     s.push_back("Push");
                     index++;
                }
                else
                {
                    s.push_back("Push");
                    s.push_back("Pop");
                }
            }
        }
        return s;
    }
};