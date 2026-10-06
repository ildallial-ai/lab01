#include <iostream>

using namespace std;

int A[5];

void trySeq(int k) {
    if (k > 0) {
        for (int val = 0; val <= 4; val++) {
            A[5 - k] = val;
            trySeq(k - 1);
        }
    }
    else {
        for (int i = 0; i < 5; i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    trySeq(5);
    return 0;
}