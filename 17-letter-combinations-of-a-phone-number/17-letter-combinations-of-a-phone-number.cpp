class Solution {
public:
    void print(int index, string digits, string output, vector<string> &ans, string mapping[]){
        if(index == digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i = 0; i<value.length(); i++){
            output.push_back(value[i]);
            print(index + 1, digits, output, ans, mapping);
            output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        string output;
        int index;
        string mapping[10] = {"", "", "abc" ,"def" ,"ghi" ,"jkl" ,"mno" ,"pqrs" ,"tuv" ,"wxyz"};
        print(0, digits, output, ans, mapping);
        return ans;                      
    }
};