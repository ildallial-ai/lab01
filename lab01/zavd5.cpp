#include <iostream>

using namespace std;

const int N = 6;
int a[N][N] = {
    {1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1}
};

void tryMazeMin(int i, int j, int z, int& k) {
    a[i][j] = 2;

    if (i - 1 >= 0 && a[i - 1][j] != 1 && a[i - 1][j] != 2) {
        tryMazeMin(i - 1, j, z + 1, k);
    }
    else if (i - 1 < 0) {
        if (z < k) k = z;
    }

    if (i + 1 < N && a[i + 1][j] != 1 && a[i + 1][j] != 2) {
        tryMazeMin(i + 1, j, z + 1, k);
    }
    else if (i + 1 >= N) {
        if (z < k) k = z;
    }

    if (j - 1 >= 0 && a[i][j - 1] != 1 && a[i][j - 1] != 2) {
        tryMazeMin(i, j - 1, z + 1, k);
    }
    else if (j - 1 < 0) {
        if (z < k) k = z;
    }

    if (j + 1 < N && a[i][j + 1] != 1 && a[i][j + 1] != 2) {
        tryMazeMin(i, j + 1, z + 1, k);
    }
    else if (j + 1 >= N) {
        if (z < k) k = z;
    }

    a[i][j] = 0;
}

int main() {
    int k = 36;
    int startI = 4, startJ = 1;

    tryMazeMin(startI, startJ, 0, k);

    cout << "Мінімальна кількість кроків: " << k << "\n";
    return 0;
}