#include "maze.h"

int main() {
    Maze m = Maze(20, 20);
    m.draw_ascii();
    m.krusal();
    m.draw_ascii();
    m.reset();
    m.recursive_backtracker();
    m.draw_ascii();
    return 0;
}
