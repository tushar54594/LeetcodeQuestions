class Solution {
public:
    bool canCompleteTrips(vector<int>& time, int totalTrips, long long int totalTime){
        long long totalTripsPossible = 0;
        
        for(int i=0; i<time.size(); i++){
            long long int val = time[i];
            totalTripsPossible += totalTime/val;
        }
        
        if(totalTripsPossible >= totalTrips)
            return true;
        else
            return false;
    }
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        
        long long int l = 1; //constraint given in question
        long long int h = 1e14;
        
        while(l<=h){
            long long int mid = l + (h-l)/2;
            if(canCompleteTrips(time, totalTrips, mid))
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};