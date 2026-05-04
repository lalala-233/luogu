#include <cstdint>
#include <iomanip>
#include <iostream>

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

    int64_t players, scores;
    cin >> players >> scores;

    int64_t max_score = 0;
    for (int64_t i = 0; i < players; i++) {
        int64_t max = 0;
        int64_t min = 114514;
        int64_t sum = 0;
        for (int64_t j = 0; j < scores; j++) {
            int64_t score;
            cin >> score;
            max = max > score ? max : score;
            min = min < score ? min : score;
            sum += score;
        }
        sum = sum - max - min;
        max_score = max_score > sum ? max_score : sum;
    }

    cout << std::fixed << std::setprecision(2) << (double)max_score / (scores - 2) << '\n';
}