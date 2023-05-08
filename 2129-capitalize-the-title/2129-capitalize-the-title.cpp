class Solution {
public:
    string capitalizeTitle(string title) {
        string str;
        for(auto a : title) str += tolower(a);
        
        int count = 0;
        int index = -1;
        for(int i=0; i<str.size(); i++)
        {
            if(index == -1) index = i;
            if(str[i] != ' ') count++;
            else
            {
                if(count > 2) str[index] =  toupper(str[index]);
                count = 0;
                index = -1;
            }
        }
        
        //last wla ke liye
        if(count > 2) str[index] = toupper(str[index]);
        
        return str;
    }
};