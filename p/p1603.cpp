#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}
const unordered_map<string, int> MAP = {
    { "zero", (0 * 0) % 100 },       { "one", (1 * 1) % 100 },
    { "a", (1 * 1) % 100 },          { "another", (1 * 1) % 100 },
    { "first", (1 * 1) % 100 },      { "two", (2 * 2) % 100 },
    { "both", (2 * 2) % 100 },       { "second", (2 * 2) % 100 },
    { "three", (3 * 3) % 100 },      { "third", (3 * 3) % 100 },
    { "four", (4 * 4) % 100 },       { "five", (5 * 5) % 100 },
    { "six", (6 * 6) % 100 },        { "seven", (7 * 7) % 100 },
    { "eight", (8 * 8) % 100 },      { "nine", (9 * 9) % 100 },
    { "ten", (10 * 10) % 100 },      { "eleven", (11 * 11) % 100 },
    { "twelve", (12 * 12) % 100 },   { "thirteen", (13 * 13) % 100 },
    { "fourteen", (14 * 14) % 100 }, { "fifteen", (15 * 15) % 100 },
    { "sixteen", (16 * 16) % 100 },  { "seventeen", (17 * 17) % 100 },
    { "eighteen", (18 * 18) % 100 }, { "nineteen", (19 * 19) % 100 },
    { "twenty", (20 * 20) % 100 }
};
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int32_t> numbers;

    string s;
    for (int32_t i = 0; i < 6; i++) {
        cin >> s;
        if (i == 5 && s.back() == '.') {
            s.pop_back();
        }
        auto it = MAP.find(s);
        if (it != MAP.end()) {
            numbers.push_back(it->second);
        }
    }
    std::sort(numbers.begin(), numbers.end());
    int64_t result = 0;
    for (auto number: numbers) {
        result = 100 * result + number;
    }
    println(result);
}