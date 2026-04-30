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

    int64_t size;
    cin >> size;

    int64_t torch;
    cin >> torch;

    int64_t stone;
    cin >> stone;

    vector<int64_t> v(size * size, -1);
    const int64_t TORCHS = 13;
    const int64_t TORCH_X[TORCHS] = { 0, -1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, 0 };
    const int64_t TORCH_Y[TORCHS] = { 2, 1, 1, 1, 0, 0, 0, 0, 0, -1, -1, -1, -2 };
    for (int64_t i = 0; i < torch; i++) {
        int64_t x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        for (int64_t j = 0; j < TORCHS; j++) {
            int64_t light_x = x + TORCH_X[j];
            int64_t light_y = y + TORCH_Y[j];
            if (light_x >= 0 && light_y >= 0 && light_x < size && light_y < size) {
                v[light_y * size + light_x] = 1;
            }
        }
    }
    for (int64_t i = 0; i < stone; i++) {
        int64_t x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        for (int64_t x_offset = -2; x_offset <= 2; x_offset++) {
            for (int64_t y_offset = -2; y_offset <= 2; y_offset++) {
                int64_t light_x = x + x_offset;
                int64_t light_y = y + y_offset;
                if (light_x >= 0 && light_y >= 0 && light_x < size && light_y < size) {
                    v[light_y * size + light_x] = 1;
                }
            }
        }
    }
    int64_t count = 0;
    for (const auto& light: v) {
        if (light == -1) {
            count += 1;
        }
    }
    println(count);
}
