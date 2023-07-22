class Solution {
public:
    unordered_map<string, double> mp;
    vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    double helper( int N, int K , int row, int col ) {
        
        if ( row < 0 || row >= N || col < 0 || col >= N ) 
            return 0; 
        
        if (K==0)
            return 1;  //one possibility over, return now
        
        string key = to_string(K) + "_" + to_string(row) + "_" + to_string(col);
        
        if(mp.find(key) != mp.end()) 
            return mp[key];
        
        double ans = 0;
        for(auto &dir : directions) {
            int new_row = row + dir.first;
            int new_col = col + dir.second;
            ans += (double)helper(N, K-1, new_row, new_col);
        }
        
        return mp[key] = (double)(ans/8.0); 
    }
    
    
    double knightProbability(int n, int k, int row, int column) {
        return helper( n , k , row , column); 
    }
};