#include <iostream>

using namespace std;

int A[5];

bool hasDuplicates() {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (A[i] == A[j]) {
                return true;
            }
        }
    }
    return false;
}

void trySeq(int k) {
    if (k > 0) {
        for (int val = 0; val <= 4; val++) {
            A[5 - k] = val;
            trySeq(k - 1);
        }
    }
    else {
        if (!hasDuplicates()) {
            for (int i = 0; i < 5; i++) {
                cout << A[i] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    trySeq(5);
    return 0;
}