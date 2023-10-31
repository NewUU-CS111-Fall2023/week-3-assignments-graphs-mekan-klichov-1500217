/*
 * Author: Mekan Klichov
 * Date: 31.10.2023
 * Name: Mekan Klichov
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;



struct State {
    int row, col, spikesLeft;
    State(int r, int c, int s) : row(r), col(c), spikesLeft(s) {}
};

int task2() {
    int n, m, j;
    cin >> n >> m >> j;

    vector<vector<char>> maze(n, vector<char>(m));
    int startX, startY, endX, endY;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == '@') {
                startX = i;
                startY = j;
            } else if (maze[i][j] == 'x') {
                endX = i;
                endY = j;
            }
        }
    }

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(j + 1, false)));
    queue<State> q;
    q.push(State(startX, startY, j));
    visited[startX][startY][j] = true;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        int r = curr.row;
        int c = curr.col;
        int spikes = curr.spikesLeft;

        if (r == endX && c == endY) {
            cout << "SUCCESS" << endl;
            return 0;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int newRow = r + dr[i];
            int newCol = c + dc[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                if (maze[newRow][newCol] == '.' && !visited[newRow][newCol][spikes]) {
                    q.push(State(newRow, newCol, spikes));
                    visited[newRow][newCol][spikes] = true;
                } else if (maze[newRow][newCol] == 's' && spikes > 0 && !visited[newRow][newCol][spikes - 1]) {
                    q.push(State(newRow, newCol, spikes - 1));
                    visited[newRow][newCol][spikes - 1] = true;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
