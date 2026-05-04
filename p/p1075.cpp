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
int64_t get_greater_factor(const int64_t NUMBER) {
    if (NUMBER % 2 == 0) {
        return NUMBER / 2;
    }
    for (int64_t i = 3; i * i <= NUMBER; i += 2) {
        if (NUMBER % i == 0) {
            return NUMBER / i;
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t number;
    cin >> number;
    println(get_greater_factor(number));
}