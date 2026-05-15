#include <cstdint>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t times;
    cin >> times;
    bool print_yet = false;
    for (int64_t i = times; i >= 0; i--) {
        int64_t temp;
        cin >> temp;
        if (temp != 0) {
            if (print_yet && temp > 0) {
                print('+');
            }
            if (i != 0) {
                if (temp == -1) {
                    print('-');
                } else if (temp != 1) {
                    print(temp);
                }
            } else {
                print(temp);
            }
            if (i != 0) {
                print('x');
            }
            if (i > 1) {
                print('^');
                print(i);
            }
            print_yet = true;
        }
    }
    if (!print_yet) {
        print('0');
    }
    print('\n');
}