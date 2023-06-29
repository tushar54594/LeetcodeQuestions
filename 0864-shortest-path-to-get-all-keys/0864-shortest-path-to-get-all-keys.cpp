class Solution {
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    // Checking if new coordinates are going out of grid on not
    bool isValid(int x, int y, int rows, int cols) {
        return (x>=0 and x<rows and y>=0 and y<cols);
    }

    // Function to check whether current char is lowercase
    bool isLowerCase(char ch) {
        return (ch>='a' and ch<='z');
    }

    // Function to check whether current char is uppercase
    bool isUpperCase(char ch) {
        return (ch>='A' and ch<='Z');
    }


    // Return number of set bits in number
    int getNumberOfBits(int mask)
    {
        int ans = 0;

        while (mask != 0) {
            ans += (mask & 1);
            mask >>= 1; // Right Shift (same as divide by 2).
        }

        return ans;
    }

public:

    int shortestPathAllKeys(vector<string>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int keys = 0;
        
        // {i, j, mask}
        queue<vector<int>> q;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {

                if(isLowerCase(grid[i][j])) {
                    keys++;
                }

                if(grid[i][j] == '@') {
                    q.push({i, j, 0});
                }
            }
        }
        set<vector<int>> vis; // {i,j, currMask}
        int steps = 0;
        
        while(not q.empty()) {
            int sz = q.size();

            for(int i=0; i<sz; i++) {

                vector<int> currCell = q.front();
                q.pop();

                int x = currCell[0];
                int y = currCell[1];
                int mask = currCell[2];

                // If we have collected all keys the return steps 
                if(getNumberOfBits(mask) == keys){
                    return steps;
                }

                for(int k=0; k<4; k++){
                    int newX = x + dx[k];
                    int newY = y + dy[k];

                    if (isValid(newX, newY, rows, cols) == false or grid[newX][newY] == '#') {
                        continue;
                    }

                    char newChar = grid[newX][newY];
                    int newMask = mask;

                    // If new char is lowercase, means we find a key so add it to our mask.
                    if (isLowerCase(newChar)) {
                        newMask |= (1 << (newChar - 'a'));
                    }

                    // If we have already visited current cell and mask is not updated then skip the current cell otherwise check if current lock (capital letter) key is present or not. 
                    if(
                        vis.find({newX, newY, newMask}) != vis.end() or
                      (isUpperCase(newChar) and !(mask&(1<<(newChar-'A'))))
                      )
                            continue;
                    
                    // Lastly push new char and newmask
                    q.push({newX, newY, newMask});
                    vis.insert({newX, newY, newMask});
                }
            }

            // Increase steps at each iteration
            steps++;
        }

        return -1;
    }
};