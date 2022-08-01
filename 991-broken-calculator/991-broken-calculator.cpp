class Solution {
public:
    int brokenCalc(int startValue, int target) {
        //if startValue is greater than target, then we cannot multiply startValue by 2 so the only option is to subtract 1 in each iteration
        if(startValue >= target)
            return startValue - target;
        
        //reverse the logic in the question i.e. reach startValue from target by either adding 1 or dividing by 2 since in the first logic, we are not sure if we'll reach the target value in minimum no of steps
        
        //by this logic, we are eliminating the other possibility of the next steps. In the earlier logic, we can either subtract 1 or divide by 2 but in this logic, we are pretty sure that if the target value is even then divide by 2, else if target is odd, then add 1 to it
        
        if(target%2 == 0)
        {
            return 1 + brokenCalc(startValue, target/2);
        }
        else
            return 1 + brokenCalc(startValue, target+1);
        
    }
};