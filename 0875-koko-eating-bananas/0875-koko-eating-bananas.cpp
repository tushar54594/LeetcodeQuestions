class Solution {
public:
    long long calculateHours(vector<int>& piles, int k){
        long long totalHours = 0;
        for(int i=0; i<piles.size(); i++){
            totalHours += ceil((double)piles[i]/(double)k);
        }
        
        return totalHours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        //find the max element in the array
        int maxi = *max_element(piles.begin(), piles.end());
        
        int low = 1, high = maxi;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long totalHours = calculateHours(piles, mid);
            if(totalHours <= h) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
};