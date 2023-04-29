class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        set<int> a;
        set<int> b;
        for(int i=0; i<A.size(); i++)
        {
            vector<int> v;
            a.insert(A[i]);
            b.insert(B[i]);
            
            set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(v, end(v)));
            ans.push_back(v.size());
        }
        return ans;
    }
};