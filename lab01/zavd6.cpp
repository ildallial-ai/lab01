#include <iostream>
#include <algorithm>

using namespace std;

const int ROWS = 4;
int tri[ROWS][ROWS] = {
    {7, 0, 0, 0},
    {3, 8, 0, 0},
    {8, 1, 0, 0},
    {2, 7, 4, 4}
};

int getMaxSum(int r, int c) {
    if (r == ROWS - 1) {
        return tri[r][c];
    }

    int downLeft = getMaxSum(r + 1, c);
    int downRight = getMaxSum(r + 1, c + 1);

    return tri[r][c] + max(downLeft, downRight);
}

int main() {
    cout << "Найбільша сума шляху: " << getMaxSum(0, 0) << "\n";
    return 0;
}