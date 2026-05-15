#include <cctype>
#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}

void print_times(const auto& v, int32_t times) {
    for (int32_t i = 0; i < times; i++) {
        print(v);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t fill_type;
    cin >> fill_type;
    const int64_t LOWERCASE = 1;
    const int64_t UPPERCASE = 2;
    const int64_t SHADOW = 3;

    int64_t times;
    cin >> times;

    int64_t reverse_control;
    cin >> reverse_control;
    const int64_t REVERSE = 2;

    char previous = -1;
    while (true) {
        char temp;
        cin >> temp;
        if (cin.fail()) {
            break;
        }
        if (temp != '-' || previous == -1) {
            print(temp);
            previous = temp;
        } else {
            char next;
            cin >> next;
            if (cin.fail()) {
                print(temp);
                break;
            }
            if ((bool(isalpha(previous)) && bool(isalpha(next)))
                || (bool(isdigit(previous)) && bool(isdigit(next))))
            {
                if (next <= previous) {
                    print(temp);
                } else {
                    for (int32_t i = 1; i < (next - previous); i++) {
                        if (reverse_control == REVERSE) {
                            if (fill_type == LOWERCASE) {
                                print_times(char(next - i), times);
                            } else if (fill_type == UPPERCASE) {
                                print_times((char)toupper(next - i), times);
                            } else {
                                print_times('*', times);
                            }
                        } else {
                            if (fill_type == LOWERCASE) {
                                print_times(char(previous + i), times);
                            } else if (fill_type == UPPERCASE) {
                                print_times((char)toupper(previous + i), times);
                            } else {
                                print_times('*', times);
                            }
                        }
                    }
                }
            } else {
                print(temp);
            }
            print(next);
            previous = next;
        }
    }
    print('\n');
}