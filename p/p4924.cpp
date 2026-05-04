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
void rotate(
    vector<int64_t>& matrix,
    int64_t x,
    int64_t y,
    const int64_t R,
    const int64_t DIRECTION,
    const int64_t SIZE
) {
    const int64_t CLOCKWISE = 0;
    const int64_t ROTATED_SIZE = 2 * R + 1;
    vector<int64_t> rotated_part(ROTATED_SIZE * ROTATED_SIZE, 0);
    for (int64_t i = 0; i < ROTATED_SIZE; i++) {
        for (int64_t j = 0; j < ROTATED_SIZE; j++) {
            int64_t origin_x, origin_y;
            if (DIRECTION == CLOCKWISE) {
                origin_x = j;
                origin_y = ROTATED_SIZE - 1 - i;
            } else {
                origin_x = ROTATED_SIZE - 1 - j;
                origin_y = i;
            }
            origin_x = x - 1 - R + origin_x;
            origin_y = y - 1 - R + origin_y;
            rotated_part[j * ROTATED_SIZE + i] = matrix[origin_y * SIZE + origin_x];
        }
    }
    for (int64_t i = 0; i < ROTATED_SIZE; i++) {
        for (int64_t j = 0; j < ROTATED_SIZE; j++) {
            matrix[(y - 1 - R + j) * SIZE + (x - 1 - R + i)] = rotated_part[j * ROTATED_SIZE + i];
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t size, command_count;
    cin >> size >> command_count;

    vector<int64_t> matrix(size * size);
    for (int64_t i = 1; i <= size * size; i++) {
        matrix[i - 1] = i;
    }

    for (int64_t i = 0; i < command_count; i++) {
        int64_t x, y, r, direction;
        cin >> y >> x >> r >> direction;
        rotate(matrix, x, y, r, direction, size);
    }
    for (int64_t i = 0; i < size * size; i++) {
        print(matrix[i]);
        if ((i + 1) % size == 0) {
            print('\n');
        } else {
            print(' ');
        }
    }
}