#include "maze.h"
// #include <algorithm>
// #include <vector>
// #include <cstdlib>
// #include <iostream>
// using namespace std;

Maze::Maze(int _height, int _width) {
    
    srand(time(0));
    height = _height;
    width = _width;
    maze.assign(height, vector<int>(width));

    for(int i = 0; i < 4; i++)
        directions[i] = 1 << i;
    
    dx[U] = -1, dx[R] = 0, dx[D] = 1, dx[L] = 0;
    dy[U] = 0, dy[R] = 1, dy[D] = 0, dy[L] = -1;
    opposite[U] = D, opposite[R] = L,
    opposite[D] = U, opposite[L] = R;
}

void Maze::reset() {
    maze.assign(height, vector<int>(width,0));
}

bool Maze::out_of_bounds(int nx, int ny) {
    return nx < 0 || ny < 0 || nx >= height || ny >= width;
}

void Maze::draw_ascii() {
    // cout << string(width * 2 + 1, '_') << endl;
    cout << " ";
    for(int j = 0; j < width; j++)
        cout << "_ ";
    cout << endl;
    for(int i = 0; i < height; i ++) {
        cout << "|";
        for(int j = 0; j < width; j ++) {
            cout << ((maze[i][j] & D) ? ' ': '_');
            cout << ((maze[i][j] & R) ? ' ': '|');
        }
        cout << endl;
    }
}

void Maze::_recursive_backtrack_dfs(int x, int y) {
    random_shuffle(directions, directions + 4);
    for(int dir : directions) {
        int nx = dx[dir] + x;
        int ny = dy[dir] + y;

        if(out_of_bounds(nx, ny) || maze[nx][ny]) {
            continue;
        }

        maze[x][y] |= dir;
        maze[nx][ny] |= opposite[dir];
        _recursive_backtrack_dfs(nx, ny);
    }
}

void Maze::recursive_backtracker() {
    _recursive_backtrack_dfs(0, 0);
}

