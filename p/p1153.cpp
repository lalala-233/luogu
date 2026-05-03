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
void skip_prefix_zero(string::reverse_iterator& it, string::reverse_iterator end) {
    while (*it == '0' && it != end) {
        ++it;
    }
}
void print_until_end(string::reverse_iterator& it, string::reverse_iterator end) {
    while (it != end) {
        print(*it);
        ++it;
    }
}
void print_until_end_with_count(string::reverse_iterator& it, string::reverse_iterator end) {
    int64_t print_count = 0;
    while (it != end) {
        print(*it);
        ++it;
        ++print_count;
    }
    if (print_count == 0) {
        print(0);
    }
}
void print_until_end_ignore_tail_zero_with_count(
    string::reverse_iterator& it,
    string::reverse_iterator end
) {
    string temp;
    bool have_print = false;
    while (it != end) {
        if (*it == '0') {
            temp.push_back(*it);
        } else {
            print(temp);
            print(*it);
            have_print = true;
            temp.clear();
        }
        ++it;
    }
    if (!have_print) {
        print(0);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    if (s.back() == '%') {
        auto it = s.rbegin();
        ++it;
        skip_prefix_zero(it, s.rend());
        print_until_end_with_count(it, s.rend());
        println('%');
        return 0;
    }

    int64_t position = s.find('/');
    if (position != string::npos) {
        auto it = s.rbegin() + s.size() - position;
        skip_prefix_zero(it, s.rend());
        print_until_end_with_count(it, s.rend());
        print('/');

        it = s.rbegin();
        skip_prefix_zero(it, s.rbegin() + s.size() - position - 1);
        print_until_end(it, s.rbegin() + s.size() - position - 1);
        print('\n');
        return 0;
    }

    position = s.find('.');
    if (position != string::npos) {
        auto it = s.rbegin() + s.size() - position;
        skip_prefix_zero(it, s.rend());
        print_until_end_with_count(it, s.rend());
        print('.');

        it = s.rbegin();
        skip_prefix_zero(it, s.rbegin() + s.size() - position - 1);
        print_until_end_ignore_tail_zero_with_count(it, s.rbegin() + s.size() - position - 1);
        print('\n');
        return 0;
    }

    auto it = s.rbegin();
    skip_prefix_zero(it, s.rend());
    print_until_end_with_count(it, s.rend());
    print('\n');
    return 0;
}