#include <iostream>

using namespace std;

const int N = 10;
int map[N][N] = {
    {1, 0, 0, 1, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {0, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 0, 0, 0}
};

void fillLake(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return;
    if (map[r][c] != 0) return;

    map[r][c] = 2;

    fillLake(r - 1, c);
    fillLake(r + 1, c);
    fillLake(r, c - 1);
    fillLake(r, c + 1);
}

int main() {
    int lakeCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                lakeCount++;
                fillLake(i, j);
            }
        }
    }

    cout << "Кількість озер на карті: " << lakeCount << "\n";
    return 0;
}