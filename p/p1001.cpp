#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

void println(auto v) {
    cout << v << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t a, b;
    cin >> a >> b;
    println(a + b);
}
