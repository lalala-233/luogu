#include <cstdint>
#include <iostream>
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
const uint64_t BILLION = 1000000000;
const uint64_t BILLION_LENGTH = 9;
struct BigInt {
    vector<uint32_t> inner;
    static BigInt parse(const string& number) {
        BigInt tmp;
        tmp.inner.reserve(number.size() / BILLION_LENGTH + 1);
        uint32_t temp = 0;
        uint32_t digit = 1;
        for (int32_t i = number.size() - 1; i >= 0; i--, digit *= 10) {
            if (digit == BILLION) {
                tmp.inner.push_back(temp);
                temp = 0;
                digit = 1;
            }
            temp += (number[i] - '0') * digit;
        }
        if (temp != 0) {
            tmp.inner.push_back(temp);
        }
        return tmp;
    }
    void operator*=(const BigInt& other) {
        vector<uint64_t> temp(inner.size() + other.inner.size(), 0);
        for (int32_t i = 0; i < other.inner.size(); i++) {
            for (int32_t j = 0; j < inner.size(); j++) {
                temp[i + j] += (uint64_t)other.inner[i] * (uint64_t)inner[j];
                if (temp[i + j] > BILLION * BILLION) {
                    temp[i + j + 1] += temp[i + j] / BILLION;
                    temp[i + j] = temp[i + j] % BILLION;
                }
            }
        }
        inner.resize(temp.size(), 0);
        uint64_t carry = 0;
        for (int32_t i = 0; i < temp.size(); i++) {
            inner[i] = (temp[i] + carry) % BILLION;
            carry = (temp[i] + carry) / BILLION;
        }
        if (carry != 0) {
            inner[temp.size()] = carry;
        }
    }
    void display() {
        bool print_yet = false;
        for (int32_t i = inner.size() - 1; i >= 0; i--) {
            for (uint32_t j = BILLION / 10; j >= 1; j /= 10) {
                int32_t digit = inner[i] / j % 10;
                if (digit != 0 || print_yet) {
                    print(digit);
                    print_yet = true;
                }
            }
        }
        if (!print_yet) {
            print(0);
        }
        print('\n');
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string number;
    cin >> number;
    BigInt num_1 = BigInt::parse(number);
    cin >> number;
    BigInt num_2 = BigInt::parse(number);
    num_1 *= num_2;
    num_1.display();
}