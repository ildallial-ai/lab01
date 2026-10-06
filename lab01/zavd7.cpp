#include <iostream>
#include <algorithm>

using namespace std;

const int N = 8;
int field[N][N] = {
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0}
};

int maxLen = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void findSnake(int r, int c, int currentLen) {
    maxLen = max(maxLen, currentLen);
    field[r][c] = 2;

    for (int d = 0; d < 4; d++) {
        int nr = r + dx[d];
        int nc = c + dy[d];

        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            if (field[nr][nc] == 0) {
                findSnake(nr, nc, currentLen + 1);
            }
        }
    }

    field[r][c] = 0;
}

int main() {
    findSnake(0, 0, 1);
    cout << "Максимальна довжина удава: " << maxLen << "\n";
    return 0;
}