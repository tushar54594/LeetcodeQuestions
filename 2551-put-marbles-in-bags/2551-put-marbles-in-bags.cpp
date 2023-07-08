class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> v;
        for(int i=0; i<n-1; i++) v.push_back(weights[i] + weights[i+1]);
        
        sort(v.begin(), v.end());
        //get the starting k-1 sum (min) and the ending k-1 sum (max)
        
        long long min_sum = 0;
        long long max_sum = 0;
        for(int i=0; i<k-1; i++){
            min_sum += v[i];
            max_sum += v[n-2-i];  //there are total n-1 elements in v array
        }
        
        return max_sum - min_sum;
        
     }
};