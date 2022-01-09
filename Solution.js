
/**
 * @param {string} instructions
 * @return {boolean}
 */
var isRobotBounded = function (instructions) {

    const direction = {
        NORTH: 0, EAST: 1, SOUTH: 2, WEST: 3
    };
    const TOTAL_DIRECTIONS = 4;
    let currentDirection = direction.NORTH;

    const move = [
        [0, 1], //NORTH
        [-1, 0], //EAST
        [0, -1], //SOUTH
        [1, 0]//WEST
    ];

    let x = 0;
    let y = 0;
    let size = instructions.length;

    for (let i = 0; i < size; i++) {
        let instruction = instructions.charAt(i);
        if (instruction === 'G') {
            x += move[currentDirection][0];
            y += move[currentDirection][1];
        } else if (instruction === 'L') {
            currentDirection = (currentDirection + 1) % TOTAL_DIRECTIONS;
        } else if (instruction === 'R') {
            currentDirection = (currentDirection + 3) % TOTAL_DIRECTIONS;
        }
    }

    return (x === 0 && y === 0) || currentDirection !== direction.NORTH;
};
