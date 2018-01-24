#include "maze.h"

int main() {
    Maze m = Maze(20, 20);
    m.draw_ascii();
    m.recursive_backtracker();
    m.draw_ascii();
    return 0;
}