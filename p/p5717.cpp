#include <cstdint>
#include <iostream>
#include <utility>

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

    int64_t a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
        std::swap(a, b);
    }
    if (b > c) {
        std::swap(b, c);
    }
    if (a > b) {
        std::swap(a, b);
    }

    if (a + b <= c) {
        println("Not triangle");
        return 0;
    }

    if (a * a + b * b < c * c) {
        println("Obtuse triangle");
    } else if (a * a + b * b == c * c) {
        println("Right triangle");
    } else if (a * a + b * b > c * c) {
        println("Acute triangle");
    }

    if (a == b || b == c) {
        println("Isosceles triangle");
    }
    if (a == b && b == c) {
        println("Equilateral triangle");
    }
}
