#include <cctype>
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
void tolower(string& s) {
    for (auto& c: s) {
        c = std::tolower(c);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string target;
    cin >> target;
    cin.ignore();
    tolower(target);

    int first_position = 1919810;
    char c;
    int index = 0;
    int count = 0;
    for (int position = 0;; position++) {
        bool ok = (bool)cin.get(c);
        if (c == ' ' || !ok) {
            if (index == target.size()) {
                if (position - target.size() < first_position) {
                    first_position = position - target.size();
                }
                count += 1;
            }
            index = 0;

            if (!ok) {
                break;
            }
            continue;
        }

        if (index < target.size()) {
            if (tolower(c) != target[index]) {
                index = -1;
            }
        }
        if (index != -1) {
            index += 1;
        }
        if (!ok) {
            break;
        }
    }

    if (count != 0) {
        print(count);
        print(' ');
        println(first_position);
    } else {
        println(-1);
    }
}