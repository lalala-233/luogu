#include <cmath>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

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

    string word;
    cin >> word;

    int counts[26] = { 0 };
    for (char c: word) {
        counts[c - 'a'] += 1;
    }
    int max = 0;
    int min = 114514;
    for (int count: counts) {
        max = max < count ? count : max;
        min = min > count && count != 0 ? count : min;
    }
    if (max - min == 2) {
        goto lucky;
    }
    if ((max - min) % 2 == 0 || max - min <= 1) {
        goto unlucky;
    }
    for (int i = 3; i < sqrt(max - min) + 1; i += 2) {
        if ((max - min) % i == 0) {
            goto unlucky;
        }
    }
lucky:
    println("Lucky Word");
    println(max - min);
    return 0;
unlucky:
    println("No Answer");
    println(0);
}
