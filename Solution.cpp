
#include<vector>
using namespace std;

enum class Direction {
    NORTH, EAST, SOUTH, WEST
};

class Solution {
public:

    Direction currentDirection{ Direction::NORTH};
    const int TOTAL_DIRECTIONS = 4;
    const vector<Direction> dir = {Direction::NORTH, Direction::EAST, Direction::SOUTH, Direction::WEST};
    const vector<vector<int>> move = {
        {0, 1}, //NORTH
        {-1, 0}, //EAST
        {0, -1}, //SOUTH
        {1, 0}//WEST
    };

    bool isRobotBounded(string instructions) {

        int x = 0;
        int y = 0;
        size_t size = instructions.length();

        for (size_t i = 0; i < size; i++) {
            char instruction = instructions[i];
            if (instruction == 'G') {
                x += move[static_cast<int> (currentDirection)][0];
                y += move[static_cast<int> (currentDirection)][1];
            } else {
                rotate(instruction);
            }
        }

        return (x == 0 && y == 0) || currentDirection != Direction::NORTH;
    }

    void rotate(char instruction) {
        if (instruction == 'L') {
            int newIndex = (static_cast<int> (currentDirection) + 1) % TOTAL_DIRECTIONS;
            currentDirection = dir[newIndex];
        } else if (instruction == 'R') {
            int newIndex = (static_cast<int> (currentDirection) + 3) % TOTAL_DIRECTIONS;
            currentDirection = dir[newIndex];
        }
    }
};
