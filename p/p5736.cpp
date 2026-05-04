#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>

using std::array;
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

    const size_t SIZE = 100001;
    array<bool, SIZE> is_prime;
    is_prime.fill(true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int64_t i = 2; i < SIZE; i++) {
        if (is_prime[i]) {
            for (int32_t j = i * i; j < SIZE; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int64_t n;
    cin >> n;
    bool have_print = false;
    for (int64_t i = 0; i < n; i++) {
        int64_t number;
        cin >> number;
        if (is_prime[number]) {
            if (have_print) {
                print(' ');
            }
            print(number);
            have_print = true;
        }
    }
    print('\n');
}