#include <cstddef>
#include <cstdint>
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

    int64_t n;
    cin >> n;

    string s;
    cin >> s;
    string op;
    string temp;
    for (int64_t i = 0; i < n; i++) {
        cin >> op;
        cin >> temp;
        if (op == "1") {
            s.append(temp);
            println(s);
        } else if (op == "2") {
            int64_t offset = std::stoi(temp);
            // if (s.size() <= offset) {
            //     s.clear();
            //     cin >> temp;
            // } else {
            auto start = s.begin() + offset;
            cin >> temp;
            int64_t length = std::stoi(temp);
            // if (offset + length >= s.size()) {
            //     s = string(start, s.end());
            // } else {
            auto end = start + length;
            s = string(start, end);
            // }
            // }
            println(s);

        } else if (op == "3") {
            int64_t offset = std::stoi(temp);
            // if (s.size() <= offset) {
            //     s.clear();
            //     cin >> temp;
            // }
            cin >> temp;
            s.insert(offset, temp);
            println(s);
        } else {
            int64_t position = s.find(temp);
            if (position == string::npos) {
                position = -1;
            }
            println(position);
        }
    }
}