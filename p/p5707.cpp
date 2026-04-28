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

    int32_t distance, v;
    cin >> distance >> v;
    int32_t take_minutes = distance / v;
    if (distance % v != 0) {
        take_minutes += 1;
    }

    const int32_t TARGET_TIME = 8 * 60;
    const int32_t DAY_TIME = 24 * 60;
    int32_t latest_time = TARGET_TIME - take_minutes - 10;
    if (latest_time < 0) {
        latest_time += DAY_TIME;
    }

    if (latest_time / 60 < 10) {
        print(0);
    }
    print(latest_time / 60);
    print(':');
    if (latest_time % 60 < 10) {
        print(0);
    }
    println(latest_time % 60);
}
