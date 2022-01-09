
public class Solution {

    enum Direction {
        NORTH, EAST, SOUTH, WEST;
    }
    Direction currentDirection = Direction.NORTH;
    final int TOTAL_DIRECTIONS = 4;
    int[][] move = {
        {0, 1},//NORTH
        {-1, 0},//EAST
        {0, -1},//SOUTH
        {1, 0}//WEST
    };

    public boolean isRobotBounded(String instructions) {

        int x = 0;
        int y = 0;
        int size = instructions.length();

        for (int i = 0; i < size; i++) {
            char instruction = instructions.charAt(i);
            if (instruction == 'G') {
                x += move[currentDirection.ordinal()][0];
                y += move[currentDirection.ordinal()][1];
            } else {
                rotate(instruction);
            }
        }

        return (x == 0 && y == 0) || currentDirection != Direction.NORTH;
    }

    public void rotate(char instruction) {
        if (instruction == 'L') {
            int newIndex = (currentDirection.ordinal() + 1) % TOTAL_DIRECTIONS;
            currentDirection = Direction.values()[newIndex];
        } else if (instruction == 'R') {
            int newIndex = (currentDirection.ordinal() + 3) % TOTAL_DIRECTIONS;
            currentDirection = Direction.values()[newIndex];
        }
    }
}
