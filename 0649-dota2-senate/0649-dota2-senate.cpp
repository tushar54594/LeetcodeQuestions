class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        int n = senate.size();
        for(int i=0; i<n; i++)
        {
            if(senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        
        while(!radiant.empty() && !dire.empty())
        {
            int r = radiant.front();
            int d = dire.front();
            if(r < d)
            {
                dire.pop();
                radiant.pop();
                radiant.push(r+n);
            }
            else
            {
                radiant.pop();
                dire.pop();
                dire.push(d+n);
            }
        }
        
        if(radiant.empty()) return "Dire";
        
        return "Radiant";
    }
};