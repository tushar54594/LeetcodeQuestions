class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr[arr.size()-1] + k;
        
        vector<int> v;
        set<int> s;
        for(auto a : arr)
            s.insert(a);
        
        for(int i=1; i<=n; i++)
        {
            if(s.find(i) == s.end())
                v.push_back(i);
        }
        
        return v[k-1];
    }
};

//max value to check will be last value + k