class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(int i=0; i<address.size(); i++)
        {
            if(address[i] != '.') ans += address[i];
            else if(address[i] == '.')
            {
                ans += "[.]";
            }
        }
        
        return ans;
    }
};