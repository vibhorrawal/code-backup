class Solution {
    void change(int &direction, char delta){
        if(delta == 'R')
            direction++;
        else
            direction--;
        direction = direction % 4;
        if(direction < 0)
            direction += 4;
    }
    void move(int direction, int &x, int &y){
        if(direction == 0) // N
            y++;
        else if(direction == 1) // E
            x++;
        else if(direction == 2) // S
            y--;
        else // W
            x--;
    }
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, direction = 0; // direction -> N: 0 :: E: 1 :: S: 2 :: W: 3
        for(char in: instructions){
            if(in == 'G')
                move(direction, x, y);
            else
                change(direction, in);
        }
        return (x == 0 && y == 0) || direction != 0;
    }
};
