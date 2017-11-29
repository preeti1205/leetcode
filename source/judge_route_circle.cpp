/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true

Example 2:
Input: "LL"
Output: false

*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int net_x = 0;
        int net_y = 0;
        for(int i = 0; i < moves.size(); ++i){
            if (moves[i] == 'R') ++net_x;
            else if (moves[i] == 'L') --net_x;
            else if (moves[i] == 'U') ++net_y;
            else if (moves[i] == 'D') --net_y;
        }
        return (net_x == 0 && net_y == 0);
    }
};
