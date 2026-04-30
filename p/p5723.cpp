#include <cmath>
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

bool is_prime(int64_t n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    int64_t sqrt_n = std::sqrt(n) + 1;
    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t max_sum;
    cin >> max_sum;
    int64_t sum = 0;
    int64_t count = 0;
    for (int i = 2;; i++) {
        if (is_prime(i)) {
            sum += i;
            if (sum > max_sum) {
                break;
            }
            println(i);
            count++;
        }
    }
    println(count);
}
