class Solution {
public:
    bool isRobotBounded(string instructions) {
        //if after performing the initial set of instructions, the robot is facing towards the north direction, then there is no possible way in which he can return to origin
        
        char curr_dir = 'N'; //initial direction is north
        int x = 0, y = 0; //initiaL position is origin
        
        for(int i=0; i<instructions.size(); i++)
        {
            if(instructions[i] == 'G')
            {
                if(curr_dir == 'N')
                    y++;
                else if(curr_dir == 'E')
                    x++;
                else if(curr_dir == 'W')
                    x--;
                else if(curr_dir == 'S')
                    y--;
            }
            //if instruction is either left or right, then we just have to change the current direction
            else
            {
                char incoming = instructions[i];
                if(curr_dir == 'N')
                    curr_dir = (incoming == 'L') ? 'W' : 'E';
                else if(curr_dir == 'E')
                    curr_dir = (incoming == 'L') ? 'N' : 'S';
                else if(curr_dir == 'W')
                    curr_dir = (incoming == 'L') ? 'S' : 'N';
                else if(curr_dir == 'S')
                    curr_dir = (incoming == 'L') ? 'E' : 'W';
            }
        }
        
        if(x == 0 && y == 0 || curr_dir != 'N')
            return true;
        else 
            return false;
    }
};