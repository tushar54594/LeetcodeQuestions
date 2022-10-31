class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = n - 1; i>=0 ; i--){
            int element = arr[i];

            while(s.top() != -1 && arr[s.top()] >= element)
                s.pop();

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = 0; i<n ; i++){
            int element = arr[i];

            while(s.top() != -1 && arr[s.top()] >= element)
                s.pop();

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);
        
        int area = INT_MIN;
        for(int i = 0; i<n; i++){
            int length = heights[i];
            if(next[i] == -1)
                next[i] = n;
            
            int breadth = next[i] - prev[i] - 1;
            
            int newArea = length*breadth;
            area = max(area,newArea);   
        }
        return area;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0) 
            return 0;
        int n = matrix[0].size();
        int result = 0;
        vector<int> histogram(n, 0); //array of n elements each with a value 0
         
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;  //if 1. then increment the height of histogram
                else
                    histogram[j]=0;   //if 0, then make the height of histogram as 0
            }
            
            result = max(result, largestRectangleArea(histogram));
        }
        return result;
    }
};