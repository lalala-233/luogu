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
const string NUMBERS =
    "XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXXX.X...X...X...X.X.X.X...X.....X.X.X.X.XX.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXXX.X...X.X.....X...X...X.X.X...X.X.X...XXXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX";
void print_number(int number, int line) {
    const int LENGTH = 3 * 10 + 9;
    int offset = 4 * number;
    for (int i = 0; i < 3; i++) {
        print(NUMBERS[line * LENGTH + offset + i]);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string digit;
    cin >> digit;
    string numbers;
    cin >> numbers;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < numbers.size(); j++) {
            print_number(numbers[j] - '0', i);
            if (j == numbers.size() - 1) {
                print('\n');
            } else {
                print('.');
            }
        }
    }
}