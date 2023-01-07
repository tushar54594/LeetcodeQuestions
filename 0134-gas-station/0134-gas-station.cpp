class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0;
        int totalGas = 0;
        int n = gas.size();
        
        for(int i=0; i<n; i++)
        {
            totalCost += cost[i];
            totalGas += gas[i];
        }
        
        if(totalGas < totalCost)
            return -1;
        
        int start = 0, fuel = 0;
        for(int i=0; i<n; i++)
        {
            if(fuel < 0)
            {
                fuel = 0;
                start = i;
            }
            
            fuel = fuel + gas[i] - cost[i];
        }
        
        return start;
    }
};