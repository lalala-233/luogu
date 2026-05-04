#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
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

    vector<int64_t> set;
    for (int64_t n; cin >> n;) {
        if (std::find(set.begin(), set.end(), n) == set.end()) {
            set.push_back(n);
        }
    }
    int64_t sum = std::accumulate(set.begin(), set.end(), 0);
    println(sum << (set.size() - 1));
}