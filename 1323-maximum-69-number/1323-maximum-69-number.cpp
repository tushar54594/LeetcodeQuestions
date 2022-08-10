class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        int temp = num;
        while(temp>0)
        {
            int digit = temp%10;
            arr.push_back(digit);
            temp = temp/10;
        }
        reverse(arr.begin(),arr.end());
        int maxi = num;
        for(int i=0; i<arr.size(); i++)
        { 
            int prev = arr[i];
            if(arr[i] == 6)
                arr[i] = 9;
            
            int result = 0;
            for(int i=0; i<arr.size(); i++)
                result = result*10 + arr[i];
            
            maxi = max(maxi, result);
            
            if(prev == 6)
                arr[i] = 6;
        }
        return maxi;
    }
};