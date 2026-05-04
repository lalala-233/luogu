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
bool is_prime(const int64_t NUMBER) {
    if (NUMBER == 2) {
        return true;
    }
    if (NUMBER % 2 == 0) {
        return false;
    }
    for (int64_t i = 3; i * i <= NUMBER; i += 2) {
        if (NUMBER % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t left, right;
    cin >> left >> right;

    const int64_t SPECIAL[] = { 5, 7, 11 };
    for (int64_t number: SPECIAL) {
        if (left <= number && number <= right) {
            println(number);
        }
    }
    int64_t number;
    for (int64_t i_0 = 1; i_0 <= 9; i_0 += 2) {
        for (int64_t i_1 = 0; i_1 <= 9; i_1++) {
            number = i_0 * 101 + i_1 * 10;
            if (left <= number && number <= right && is_prime(number)) {
                println(number);
            }
        }
    }
    for (int64_t i_0 = 1; i_0 <= 9; i_0 += 2) {
        for (int64_t i_1 = 0; i_1 <= 9; i_1++) {
            for (int64_t i_2 = 0; i_2 <= 9; i_2++) {
                number = i_0 * 10001 + i_1 * 1010 + i_2 * 100;
                if (left <= number && number <= right && is_prime(number)) {
                    println(number);
                }
            }
        }
    }
    for (int64_t i_0 = 1; i_0 <= 9; i_0 += 2) {
        for (int64_t i_1 = 0; i_1 <= 9; i_1++) {
            for (int64_t i_2 = 0; i_2 <= 9; i_2++) {
                for (int64_t i_3 = 0; i_3 <= 9; i_3++) {
                    number = i_0 * 1000001 + i_1 * 100010 + i_2 * 10100 + i_3 * 1000;
                    if (left <= number && number <= right && is_prime(number)) {
                        println(number);
                    }
                }
            }
        }
    }
}