#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}

struct BigInt {
    std::vector<uint32_t> digits_;
    void normalize() {
        while (!digits_.empty() && digits_.back() == 0) {
            digits_.pop_back();
        }
    }
    explicit BigInt(uint32_t n): digits_ { n } {}
    const uint32_t BILLION = 1000000000;
    BigInt& operator+=(const BigInt& other) {
        auto max_size = std::max(digits_.size(), other.digits_.size());
        digits_.resize(max_size, 0);
        uint64_t carry = 0;
        for (int i = 0; i < max_size; i++) {
            uint64_t a = (i < digits_.size()) ? digits_[i] : 0;
            uint64_t b = (i < other.digits_.size()) ? other.digits_[i] : 0;
            uint64_t sum = a + b + carry;
            digits_[i] = static_cast<int32_t>(sum % BILLION);
            carry = sum / BILLION;
        }
        if (carry != 0) {
            digits_.push_back(static_cast<uint32_t>(carry));
        }
        return *this;
    }
    BigInt& operator*=(uint32_t factor) {
        if (factor == 0) {
            digits_.clear();
            return *this;
        }
        uint64_t carry = 0;
        for (auto& digit: digits_) {
            uint64_t product = static_cast<uint64_t>(digit) * factor + carry;
            digit = static_cast<uint32_t>(product % BILLION);
            carry = product / BILLION;
        }
        if (carry != 0) {
            digits_.push_back(static_cast<uint32_t>(carry));
        }
        return *this;
    }
    void print() {
        if (digits_.empty()) {
            println(0);
            return;
        }
        ::print(digits_.back());
        for (int i = digits_.size() - 2; i >= 0; i--) {
            uint32_t digit = digits_[i];
            for (uint64_t j = BILLION / 10; j != 0; j /= 10) {
                ::print(digit / j);
                digit = digit % j;
            }
        }
        ::print('\n');
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t n;
    cin >> n;
    BigInt sum = BigInt(0);
    BigInt fibonacci = BigInt(1);

    for (int32_t i = 1; i <= n; i++) {
        fibonacci *= i;
        sum += fibonacci;
    }
    sum.print();
}
