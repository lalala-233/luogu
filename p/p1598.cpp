#include <cctype>
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

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int32_t counts[26] = { 0 };
    int32_t max = 0;
    char c;
    while (cin >> c) {
        if (isalpha(c) != 0) {
            counts[tolower(c) - 'a'] += 1;
            max = max > counts[tolower(c) - 'a'] ? max : counts[tolower(c) - 'a'];
        }
    }
    while (max != 0) {
        for (int32_t i = 0; i < 26; i++) {
            if (counts[i] >= max) {
                print('*');
            } else {
                print(' ');
            }
            if (i != 25) {
                print(' ');
            } else {
                print('\n');
            }
        }
        max -= 1;
    }
    for (int32_t i = 0; i < 26; i++) {
        print(char('A' + i));
        if (i != 25) {
            print(' ');
        } else {
            print('\n');
        }
    }
}