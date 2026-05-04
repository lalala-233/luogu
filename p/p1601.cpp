#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}
const uint32_t BILLION = 1000000000;
vector<uint32_t> parse(string& s) {
    uint64_t result = 0;
    vector<uint32_t> v;
    for (uint32_t digit = 1; !s.empty(); digit *= 10) {
        if (digit == BILLION) {
            v.push_back(result);
            result = 0;
            digit = 1;
        }
        result = result + digit * (s.back() - '0');
        s.pop_back();
    }
    if (result != 0 || v.empty()) {
        v.push_back(result);
    }
    return v;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string number;
    cin >> number;
    auto number_1 = parse(number);
    cin >> number;
    auto number_2 = parse(number);

    number_1.resize(std::max(number_1.size(), number_2.size()), 0);
    uint32_t carry = 0;
    for (int32_t i = 0; i < number_1.size(); i++) {
        uint32_t current_2 = i >= number_2.size() ? 0 : number_2[i];
        number_1[i] = number_1[i] + current_2 + carry;
        carry = number_1[i] / BILLION;
        number_1[i] = number_1[i] % BILLION;
    }
    if (carry != 0) {
        number_1.push_back(carry);
    }

    bool should_output_zero = false;
    for (int32_t i = number_1.size() - 1; i >= 0; --i) {
        for (uint32_t digit = BILLION / 10; digit != 0; digit /= 10) {
            uint32_t result = number_1[i] / digit % 10;
            if (should_output_zero || result != 0) {
                print(result);
                should_output_zero = true;
            }
        }
    }
    if (!should_output_zero) {
        print(0);
    }
    print('\n');
}