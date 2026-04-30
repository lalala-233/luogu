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

enum class Op {
    Plus,
    Minus,
    Multiple,
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t n;
    cin >> n;

    string s;
    int64_t num_1, num_2;
    Op current_op;
    char op;
    int64_t result;
    for (int64_t i = 0; i < n; i++) {
        num_1 = -1;
        num_2 = -1;
        cin >> s;
        if (s == "a") {
            current_op = Op::Plus;
        } else if (s == "b") {
            current_op = Op::Minus;
        } else if (s == "c") {
            current_op = Op::Multiple;
        } else {
            num_1 = std::stoi(s);
        }
        if (num_1 == -1) {
            cin >> s;
            num_1 = std::stoi(s);
        }
        cin >> s;
        num_2 = std::stoi(s);
        if (current_op == Op::Plus) {
            op = '+';
            result = num_1 + num_2;
        } else if (current_op == Op::Minus) {
            op = '-';
            result = num_1 - num_2;
        } else {
            op = '*';
            result = num_1 * num_2;
        }
        print(num_1);
        print(op);
        print(num_2);
        print('=');
        println(result);
        println(
            std::to_string(num_1).size() + std::to_string(num_2).size()
            + std::to_string(result).size() + 2
        );
    }
}