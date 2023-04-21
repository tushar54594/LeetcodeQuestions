class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = 0;
        int chunk_count = 0;
        for(int i=0; i<arr.size(); i++)
        {
            maxi = max(maxi, arr[i]);
            if(maxi == i)
                chunk_count++;
        }
        return chunk_count;
    }
};

/* 
Chaining technique
maximum impact ek no ka kis index tak ja sakta hai
*/