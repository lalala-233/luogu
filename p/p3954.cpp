#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

void print(auto v) {
    cout << v;
}
void println(auto v) {
    cout << v << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t a, b, c;
    cin >> a >> b >> c;
    println(a * 2 / 10 + b * 3 / 10 + c * 5 / 10);
}
