#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

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

    std::vector<int64_t> set(10001, -1);

    int64_t n;
    cin >> n;
    std::vector<int64_t> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        set[v[i]] = 1;
    }
    std::sort(v.begin(), v.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] != v[j] + v[j] && set[v[i] - v[j]] == 1) {
                count += 1;
                break;
            }
        }
    }
    println(count);
}
