#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
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

    vector<pair<int64_t, int64_t>> in_21;
    int64_t in_11_win = 0;
    int64_t in_11_lose = 0;
    int64_t in_21_win = 0;
    int64_t in_21_lose = 0;
    for (char c; cin.get(c);) {
        if (c == 'W') {
            in_11_win += 1;
            in_21_win += 1;
        } else if (c == 'L') {
            in_11_lose += 1;
            in_21_lose += 1;
        } else if (c == 'E') {
            break;
        }
        if (in_11_win >= 11 || in_11_lose >= 11) {
            if (std::abs(in_11_win - in_11_lose) >= 2) {
                print(in_11_win);
                print(':');
                println(in_11_lose);
                in_11_win = 0;
                in_11_lose = 0;
            }
        }
        if (in_21_win >= 21 || in_21_lose >= 21) {
            if (std::abs(in_21_win - in_21_lose) >= 2) {
                in_21.emplace_back(in_21_win, in_21_lose);
                in_21_win = 0;
                in_21_lose = 0;
            }
        }
    }
    print(in_11_win);
    print(':');
    println(in_11_lose);
    in_11_win = 0;
    in_11_lose = 0;
    print('\n');
    for (auto [win, lose]: in_21) {
        print(win);
        print(':');
        println(lose);
    }
    print(in_21_win);
    print(':');
    println(in_21_lose);
    in_21_win = 0;
    in_21_lose = 0;
}