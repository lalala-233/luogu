#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::pair;

void print(const auto& v) {
    cout << v;
}
void println(const auto& v) {
    cout << v << '\n';
}

pair<int64_t, int64_t> rotate(pair<int64_t, int64_t> coord, int64_t degree, int64_t size) {
    int64_t new_x, new_y;
    if (degree == 90) {
        new_x = coord.second;
        new_y = size - 1 - coord.first;
    } else if (degree == 180) {
        new_x = size - 1 - coord.first;
        new_y = size - 1 - coord.second;
    } else if (degree == 270) {
        new_x = size - 1 - coord.second;
        new_y = coord.first;
    }
    return { new_x, new_y };
}

pair<int64_t, int64_t> reflect(pair<int64_t, int64_t> coord, int64_t size) {
    coord.first = size - 1 - coord.first;
    return coord;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t size;
    cin >> size;

    std::vector<char> source(size * size);
    std::vector<char> target(size * size);
    for (int64_t i = 0; i < size * size; i++) {
        cin >> source[i];
    }
    for (int64_t i = 0; i < size * size; i++) {
        cin >> target[i];
    }
    bool ok = true;
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = 0; j < size; j++) {
            auto new_coord = rotate({ i, j }, 90, size);
            if (source[new_coord.second * size + new_coord.first] != target[j * size + i]) {
                ok = false;
                goto break_1;
            }
        }
    }
break_1:
    if (ok) {
        println(1);
        return 0;
    }
    ok = true;
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = 0; j < size; j++) {
            auto new_coord = rotate({ i, j }, 180, size);
            if (source[new_coord.second * size + new_coord.first] != target[j * size + i]) {
                ok = false;
                goto break_2;
            }
        }
    }
break_2:
    if (ok) {
        println(2);
        return 0;
    }
    ok = true;
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = 0; j < size; j++) {
            auto new_coord = rotate({ i, j }, 270, size);
            if (source[new_coord.second * size + new_coord.first] != target[j * size + i]) {
                ok = false;
                goto break_3;
            }
        }
    }
break_3:
    if (ok) {
        println(3);
        return 0;
    }
    ok = true;
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = 0; j < size; j++) {
            auto new_coord = reflect({ i, j }, size);
            if (source[new_coord.second * size + new_coord.first] != target[j * size + i]) {
                ok = false;
                goto break_4;
            }
        }
    }
break_4:
    if (ok) {
        println(4);
        return 0;
    }
    ok = true;
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = 0; j < size; j++) {
            auto new_coord = rotate(reflect({ i, j }, size), 90, size);
            if (source[new_coord.second * size + new_coord.first] != target[j * size + i]) {
                ok = false;
                goto break_5_1;
            }
        }
    }
break_5_1:
    if (ok) {
        println(5);
        return 0;
    }
    ok = true;
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = 0; j < size; j++) {
            auto new_coord = rotate(reflect({ i, j }, size), 180, size);
            if (source[new_coord.second * size + new_coord.first] != target[j * size + i]) {
                ok = false;
                goto break_5_2;
            }
        }
    }
break_5_2:
    if (ok) {
        println(5);
        return 0;
    }
    ok = true;
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = 0; j < size; j++) {
            auto new_coord = rotate(reflect({ i, j }, size), 270, size);
            if (source[new_coord.second * size + new_coord.first] != target[j * size + i]) {
                ok = false;
                goto break_5_3;
            }
        }
    }
break_5_3:
    if (ok) {
        println(5);
        return 0;
    }
    if (source == target) {
        println(6);
    } else {
        println(7);
    }
}
