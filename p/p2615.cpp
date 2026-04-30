#include <cstdint>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

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

    size_t size;
    cin >> size;
    vector<int64_t> v(size * size, -1);

    int64_t middle_index = size / 2;
    v[middle_index] = 1;

    int32_t k_sub_1_i = 0;
    int32_t k_sub_1_j = middle_index;
    for (int32_t k = 2; k <= size * size; k++) {
        if (k_sub_1_i == 0 && k_sub_1_j != size - 1) {
            k_sub_1_i = size - 1;
            k_sub_1_j = k_sub_1_j + 1;
        } else if (k_sub_1_i != 0 && k_sub_1_j == size - 1) {
            k_sub_1_i = k_sub_1_i - 1;
            k_sub_1_j = 0;
        } else if (k_sub_1_i == 0 && k_sub_1_j == size - 1) {
            k_sub_1_i = k_sub_1_i + 1;
            k_sub_1_j = k_sub_1_j;
        } else if (v[(k_sub_1_i - 1) * size + k_sub_1_j + 1] == -1) {
            k_sub_1_i = k_sub_1_i - 1;
            k_sub_1_j = k_sub_1_j + 1;
        } else {
            k_sub_1_i = k_sub_1_i + 1;
            k_sub_1_j = k_sub_1_j;
        }
        v[k_sub_1_i * size + k_sub_1_j] = k;
    }
    for (int32_t i = 0; i < size; i++) {
        for (int32_t j = 0; j < size; j++) {
            print(v[i * size + j]);
            print(' ');
        }
        print('\n');
    }
}