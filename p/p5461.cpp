#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}
void print(int64_t i, int64_t j, int64_t n) {
    const int64_t SIZE = 1 << (n - 1);
    if (n == 0) {
        print(1);
    } else if (i < SIZE && j < SIZE) {
        print(0);
    } else if (i >= SIZE && j >= SIZE) {
        print(i - SIZE, j - SIZE, n - 1);
    } else if (i >= SIZE) {
        print(i - SIZE, j, n - 1);
    } else if (j >= SIZE) {
        print(i, j - SIZE, n - 1);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t n;
    cin >> n;
    const int64_t SIZE = 1 << n;
    for (int64_t i = 0; i < SIZE; i++) {
        for (int64_t j = 0; j < SIZE; j++) {
            print(j, i, n);
            if (j == SIZE - 1) {
                print('\n');
            } else {
                print(' ');
            }
        }
    }
}