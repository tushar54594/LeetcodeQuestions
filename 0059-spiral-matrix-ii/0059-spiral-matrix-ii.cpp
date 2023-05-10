class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int top = 0, down = n-1, left = 0, right = n-1;
        int dir = 0;
        int val = 1;
        while(top<=down && left<=right)
        {
            if(dir==0){
                for(int i = left; i<=right; i++)
                {
                    v[top][i] = val;
                    val++;
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top; i<=down; i++)
                {
                    v[i][right] = val;
                    val++;
                }
                right--;              
            }
            else if(dir == 2){
                for(int i = right; i>= left; i--)
                {
                    v[down][i] = val;
                    val++;
                }
                down--;
            }
            else if(dir == 3){
                for(int i = down; i>=top; i--)
                {
                    v[i][left] = val;
                    val++;
                }
                left++;
            }
            dir = (dir+1)%4;
        }

        return v;
    }
};