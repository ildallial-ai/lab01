#include <iostream>

using namespace std;

const int N = 6;
int a[N][N] = {
    {1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};

void tryMaze(int i, int j, int z) {
    a[i][j] = 2;

    if (i - 1 >= 0 && a[i - 1][j] != 1 && a[i - 1][j] != 2) {
        tryMaze(i - 1, j, z + 1);
    }
    else if (i - 1 < 0) {
        cout << "Вихід знайдено за кроків: " << z << "\n";
    }

    if (i + 1 < N && a[i + 1][j] != 1 && a[i + 1][j] != 2) {
        tryMaze(i + 1, j, z + 1);
    }
    else if (i + 1 >= N) {
        cout << "Вихід знайдено за кроків: " << z << "\n";
    }

    if (j - 1 >= 0 && a[i][j - 1] != 1 && a[i][j - 1] != 2) {
        tryMaze(i, j - 1, z + 1);
    }
    else if (j - 1 < 0) {
        cout << "Вихід знайдено за кроків: " << z << "\n";
    }

    if (j + 1 < N && a[i][j + 1] != 1 && a[i][j + 1] != 2) {
        tryMaze(i, j + 1, z + 1);
    }
    else if (j + 1 >= N) {
        cout << "Вихід знайдено за кроків: " << z << "\n";
    }

    a[i][j] = 0;
}

int main() {
    
    int startI = 4, startJ = 1;
    tryMaze(startI, startJ, 0);
    return 0;
}