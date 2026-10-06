#include <iostream>
#include <vector>

using namespace std;

const int N = 5;
int A[N];

void generate(int index) {
    if (index == N) {
        for (int i = 0; i < N; ++i) {
            cout << A[i] << " ";
        }
        cout << "\n";
        return;
    }

    A[index] = 0;
    generate(index + 1);

    A[index] = 1;
    generate(index + 1);
}

int main() {
    generate(0);
    return 0;
}
A